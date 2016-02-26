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
        button[0].checkHover(event.mouseMove.x, event.mouseMove.y);
        button[1].checkHover(event.mouseMove.x, event.mouseMove.y);
        button[2].checkHover(event.mouseMove.x, event.mouseMove.y);
        break;

        //Click button
	  case sf::Event::MouseButtonReleased:
		  if (button[0].mouseClicked() == true)
		  {
			  if (usernameString.length() > 0 && passwordString.length() > 0){
				  if (returnPress() == 0)
				  {

					  Player p;
					  p.name = usernameString;
					  p.password = passwordString;
					  DataManager d;
					  std::cout << (d.login_check(&p) == true ? "LoggedIn\n" : "Error\n");
					  if (d.login_create(&p)){ return 4; }
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
          std::cout << "Create\n";
          return 2;
        }
        else if (button[2].mouseClicked() == true)
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
        case sf::Keyboard::Right:
          moveRight();
          break;

          //Down arrow
        case sf::Keyboard::Left:
          moveLeft();
          break;

		case sf::Keyboard::Tab:
			EnteringPassword = EnteringPassword == true ? false : true;
			break;

		case sf::Keyboard::Return:
			if (usernameString.length() > 0 && passwordString.length() > 0){
				if (returnPress() == 0)
				{

					Player p;
					p.name = usernameString;
					p.password = passwordString;
					DataManager d;
					std::cout << (d.login_check(&p) == true ? "LoggedIn\n" : "Error\n");
					if (d.login_create(&p)){ return 4; }
					//TODO//
				}
				else if (returnPress() == 1)
				{
					std::cout << "Back\n";
					return 0;
				}
				EnteringPassword = EnteringPassword == true ? false : true;
			}

		default:
			char temp = isTypableText(event.key.code);
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
  if (!texture[0].loadFromFile("images/b_play.png", sf::IntRect(0, 0, 180, 60)))
    imageFail_important("images/b_play.jpg");
  if (!texture[1].loadFromFile("images/b_create.png", sf::IntRect(0, 0, 180, 60)))
    imageFail_important("images/b_create.jpg");
  if (!texture[2].loadFromFile("images/b_back.png", sf::IntRect(0, 0, 180, 60)))
    imageFail_important("images/b_back.jpg");

  //Create Login Button
  button[0].setTexture(texture[0]);
  button[0].setPosition(sf::Vector2f((width / 4) - (180 / 2), (height / 8) * 6));
  button[0].setScale(1.15f, 1.15f);
  //Create Create Button
  button[1].setTexture(texture[1]);
  button[1].setPosition(sf::Vector2f(((width / 4) * 2) - (180 / 2), (height / 8) * 6));

  //Create Back Button
  button[2].setTexture(texture[2]);
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


//Handler for Right
void Login::moveRight()
{
  if (selectedItem + 1 < 3)
  {
    button[selectedItem].animateDown();       //No animation
    selectedItem++;                           //next button
    button[selectedItem].animateUp();         //Animation
    button[selectedItem].sound_hover.play();  //Sound
  }
}


//Handler for Left
void Login::moveLeft()
{
  if (selectedItem - 1 >= 0)
  {
    button[selectedItem].animateDown();       //No animation
    selectedItem--;                           //next button
    button[selectedItem].animateUp();         //Animation
    button[selectedItem].sound_hover.play();  //Sound
  }
}

char Login::isTypableText(sf::Keyboard::Key a){
	switch (a){
	case sf::Keyboard::A:
		return 'a';
		break;
	case sf::Keyboard::B:
		return 'b';
		break;
	case sf::Keyboard::C:
		return 'c';
		break;
	case sf::Keyboard::D:
		return 'd';
		break;
	case sf::Keyboard::E:
		return 'e';
		break;
	case sf::Keyboard::F:
		return 'f';
		break;
	case sf::Keyboard::G:
		return 'g';
		break;
	case sf::Keyboard::H:
		return 'h';
		break;
	case sf::Keyboard::I:
		return 'i';
		break;
	case sf::Keyboard::J:
		return 'j';
		break;
	case sf::Keyboard::K:
		return 'k';
		break;
	case sf::Keyboard::L:
		return 'l';
		break;
	case sf::Keyboard::M:
		return 'm';
		break;
	case sf::Keyboard::N:
		return 'n';
		break;
	case sf::Keyboard::O:
		return 'o';
		break;
	case sf::Keyboard::P:
		return 'p';
		break;
	case sf::Keyboard::Q:
		return 'q';
		break;
	case sf::Keyboard::R:
		return 'r';
		break;
	case sf::Keyboard::S:
		return 's';
		break;
	case sf::Keyboard::T:
		return 't';
		break;
	case sf::Keyboard::U:
		return 'u';
		break;
	case sf::Keyboard::V:
		return 'v';
		break;
	case sf::Keyboard::W:
		return 'w';
		break;
	case sf::Keyboard::X:
		return 'X';
		break;
	case sf::Keyboard::Y:
		return 'y';
		break;
	case sf::Keyboard::Z:
		return 'z';
		break;

	case sf::Keyboard::Num1:
		return '1';
		break;
	case sf::Keyboard::Num2:
		return '2';
		break;
	case sf::Keyboard::Num3:
		return '3';
		break;
	case sf::Keyboard::Num4:
		return '4';
		break;
	case sf::Keyboard::Num5:
		return '5';
		break;
	case sf::Keyboard::Num6:
		return '6';
		break;
	case sf::Keyboard::Num7:
		return '7';
		break;
	case sf::Keyboard::Num8:
		return '8';
		break;
	case sf::Keyboard::Num9:
		return '9';
		break;
	case sf::Keyboard::Num0:
		return '0';
		break;
	case sf::Keyboard::Space:
		return ' ';
		break;

	default:
		return '\\';
	}

}