#include "LoginScene.hpp"
#include "Datamgr.h"

//Helping constuctor
Login::Login(sf::RenderWindow &window, int &re_val)
{
  name = "Login";      //set name
  setBackground("images/menu_image3.jpg");    //Set background
  getImage((float)window.getSize().x,         //Load buttons
    (float)window.getSize().y);





  EnteringPassword = false;				
  selectedItem = 0;                           //Selected item index
  re_val = update(window);                    //update and next scene
  return;                                     //return
}

Login::~Login()
{
  std::cout << "Deconstructor for Help" << std::endl;
}

//Update loop
int Login::update(sf::RenderWindow &window)
{
  //While the window open
  while (window.isOpen())
  {
    sf::Event event;

    //Look for event
    while (window.pollEvent(event))
    {
      switch (event.type)
      {
        //Event for hitting the x
      case sf::Event::Closed:
        window.close();
        exit(0);
        break;

        //Mouse over button
      case sf::Event::MouseMoved:
        button[0].checkHover(event);
        button[1].checkHover(event);
        button[2].checkHover(event);
        break;

        //Click button
	  case sf::Event::MouseButtonReleased:
		  if (button[0].mouseClicked() == true)
		  {
			  if (usernameString.length() > 0 && passwordString.length() > 0){
				  if (returnPress() == 0)
				  {

					  User p;
					  p.name = usernameString;
					  p.password = passwordString;
					  DataManager d;
					  std::cout << (d.login_check(&p) == true ? "LoggedIn\n" : "Error\n");

					  bool check = (d.login_check(&p) == true ? 1 : 0);
					  if (check){ 
						  RunningData::getInstance()->PlayerName = usernameString;
						  RunningData::getInstance()->PlayerPassword = passwordString;

						  DataManager d;
						  d.load_game(usernameString);
						  RunningData::getInstance()->displayAll();
						  if (RunningData::getInstance()->SelectedGameTime == 0){
							  RunningData::getInstance()->reset();
						  }
						  else{
							  return PlayGameScene;
						  }

						  return OptionsScene; 
					  }


				  }
				  else if (returnPress() == 1)
				  {
					  std::cout << "Back\n";
					  return MainMenuScene;
				  }
			  }

		}
        else if (button[1].mouseClicked() == true)
        {
          std::cout << "Create\n";
          return CreateScene;
        }
        else if (button[2].mouseClicked() == true)
        {
          std::cout << "Back\n";
          return MainMenuScene;
        }
        break;

        //Button Event
      case sf::Event::KeyReleased:
        switch (event.key.code)
        {
          //Esc
        case sf::Keyboard::Escape:
          return 0;
          break;
          //Up arrow

		case sf::Keyboard::Tab:
			EnteringPassword = EnteringPassword == true ? false : true;
			break;


		default:
			StringInput T = StringInput();
			char temp = T.isTypableText(event.key.code);
			if (temp == '\\'){

			}
			else{
				EnteringPassword == true ? passwordString.push_back(temp) : usernameString.push_back(temp);
			}
			if (event.key.code == sf::Keyboard::BackSpace && usernameString.length()>0 && !EnteringPassword){
				usernameString.pop_back();
			}
			if (event.key.code == sf::Keyboard::BackSpace && passwordString.length()>0 && EnteringPassword){
				passwordString.pop_back();
			}

			std::cout << (EnteringPassword == true ? passwordString : usernameString) << std::endl;

			break;

        }
        break;

      }
    }

    //Updating screen
    window.clear();
    draw(window);
    window.display();

  }
  return 0;
}

//Loading images
void Login::getImage(float width, float height)
{

  //Loading Font
  if (!font.loadFromFile("arial.ttf"))
  {
    fontFail("arial.tff");
  }
  else
  {
    //username lable
    userName_text.setFont(font);
    userName_text.setColor(sf::Color::White);
    userName_text.setString("USERNAME:");
    userName_text.setPosition(50, 50);

    //password label
    password_text.setFont(font);
    password_text.setColor(sf::Color::White);
    password_text.setString("PASSWORD:");
    password_text.setPosition(50, 100);
  }


  //Getting the images
  button[0].setTexture("images/b_play.png", sf::IntRect(0, 0, 180, 60));
  button[1].setTexture("images/b_create.png", sf::IntRect(0, 0, 180, 60));
  button[2].setTexture("images/b_back.png", sf::IntRect(0, 0, 180, 60));
  //Create Login Button

  button[0].setPosition(sf::Vector2f((width / 4) - (180 / 2), (height / 8) * 6));
  button[0].setScale(1.15f, 1.15f);
  //Create Create Button
  button[1].setPosition(sf::Vector2f(((width / 4) * 2) - (180 / 2), (height / 8) * 6));

  //Create Back Button
  button[2].setPosition(sf::Vector2f(((width / 4) * 3) - (180 / 2), (height / 8) * 6));


}


//Drawing
void Login::draw(sf::RenderWindow &window)
{
  window.draw(bk);              //Draw bk
  for (int i = 0; i < 3; i++)   //Drawing button
    window.draw(button[i]);

  passwordStringOBF = "";
  for (int i = 0; i < passwordString.length(); i++){
	  passwordStringOBF.push_back('*');
  }

  password_text.setString("Enter PASSWORD: " + passwordStringOBF);
  window.draw(password_text);   //Draw password prompt

  userName_text.setString("Enter USERNAME: " + usernameString);
  window.draw(userName_text);   //Draw username prompt

}