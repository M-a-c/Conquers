#include "CreateScene.hpp"
#include "Datamgr.h"
//Helping constuctor
Create::Create(sf::RenderWindow &window, int &re_val)
{
  name = "Create";      //set name
  setBackground("images/menu_image3.jpg");    //Set background
  getImage((float)window.getSize().x,         //Load buttons
    (float)window.getSize().y);


  EnteringPassword = false;
  selectedItem = 0;                           //Selected item index


  re_val = update(window);                    //update and next scene
  return;                                     //return
}

Create::~Create()
{
  std::cout << "Deconstructor for Help" << std::endl;
}

//Update loop
int Create::update(sf::RenderWindow &window)
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
        button[0].checkHover(event.mouseMove.x, event.mouseMove.y);
        button[1].checkHover(event.mouseMove.x, event.mouseMove.y);
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
					//std::cout << (d.login_create(&p) == false? "Created\n" : "Error\n");

					//std::cout << (d.login_check(&p) == false ? "LoggedIn\n" : "Error\n");

					bool check = (d.login_check(&p) == true ? 1 : 0);
					if (!check){
						if (d.login_create(&p)){
							RunningData::getInstance()->PlayerName = usernameString;
							RunningData::getInstance()->PlayerPassword = passwordString;
							return OptionsScene;
						}
					}
					//std::cout << "Create\n";
					//TODO//
				}
				else if (returnPress() == 1)
				{
					std::cout << "Back\n";
					return 0;
				}
			}
          //std::cout << "Create\n";
          //TODO//
        }
        else if (button[1].mouseClicked() == true)
        {
          std::cout << "Back\n";
          return 0;
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


          //Return button
		
		default:
			char temp = StringInput().isTypableText(event.key.code);
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
void Create::getImage(float width, float height)
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
    userName_text.setColor(sf::Color::Red);
    userName_text.setString("Enter USERNAME:");
    userName_text.setPosition(50, 50);

    //Message::No draw yet
    message.setFont(font);
    message.setColor(sf::Color::White);
    message.setString(" ");
    message.setPosition(50, 50);

    //password label
    password_text.setFont(font);
	password_text.setColor(sf::Color::Red);
    password_text.setString("Enter PASSWORD:");
    password_text.setPosition(50, 100);
  }


  //Getting the images
  if (!texture[0].loadFromFile("images/b_ok.png", sf::IntRect(0, 0, 180, 60)))
    imageFail_important("images/b_ok.jpg");
  if (!texture[1].loadFromFile("images/b_back.png", sf::IntRect(0, 0, 180, 60)))
    imageFail_important("images/b_back.jpg");
  

  //Create Create Button
  button[0].setTexture(texture[0]);
  button[0].setPosition(sf::Vector2f((width / 4) - (180 / 2), (height /8)*5 ));
  button[0].setScale(1.15f, 1.15f);

  //Create Back Button
  button[1].setTexture(texture[1]);
  button[1].setPosition(sf::Vector2f(((width / 4) * 3) - (180 / 2), (height /8)*5 ));

}


//Drawing
void Create::draw(sf::RenderWindow &window)
{
  window.draw(bk);              //Draw bk
  for (int i = 0; i < 2; i++)   //Drawing button
    window.draw(button[i]);
  passwordStringOBF = "";
  for (int i = 0; i < passwordString.length();i++){
	  passwordStringOBF.push_back('*');
  }

  password_text.setString("Enter PASSWORD: " + passwordStringOBF);
  window.draw(password_text);   //Draw password prompt

  userName_text.setString("Enter USERNAME: " + usernameString);
  window.draw( userName_text );   //Draw username prompt

}

