#include "HelpScene.hpp"

//Helping constuctor
Help::Help(sf::RenderWindow &window, int &re_val)
{
  name = "Help";      //set name
  text = "Welcome to the help screen, There will be pleanty of magic here soon.\n BTW hit Back  to go back";    //Message
  setBackground("images/menu_image3.jpg");    //Set background
  getImage((float)window.getSize().x,         //Load buttons
    (float)window.getSize().y);

  float width = (float)window.getSize().x;
  float height = (float)window.getSize().y;

  ButtonManager::getInstance()->addButton(new Button(None, "Back", "images/b_back.png", sf::IntRect(0, 0, 180, 60), sf::Vector2f((width / 4) - (180 / 2), (height / 8) * 6)));
  ButtonManager::getInstance()->addButton(new Button(CreateScene, "Create", "images/b_next.png", sf::IntRect(0, 0, 180, 60), sf::Vector2f(((width / 4) * 3) - (180 / 2), (height / 8) * 6)));



  selectedItem = 0;                           //Selected item index
  re_val = update(window);                    //update and next scene
  return;                                     //return

}

Help::~Help()
{
	ButtonManager::getInstance()->removeAllButtons();
	std::cout << "Deconstructor for Help" << std::endl;
}


//Updating the loop
int Help::update(sf::RenderWindow &window)
{
	//While the window open
	while (window.isOpen())
	{
		sf::Event event;


		//Look for event
		while (window.pollEvent(event))
		{
			InputManager::getInstance()->update(window, event);
			if (ButtonManager::getInstance()->changeScene){
				return ButtonManager::getInstance()->nextScene();
			}

		}

		//Clearing and drawing
		window.clear();
		draw(window);
		window.display();
	}
	return 0;
}


//Loading images
void Help::getImage(float width, float height)
{

  //Loading Font
  if (!font.loadFromFile("arial.ttf"))
  {
    fontFail("arial.tff");
  }
  else
  {
    message.setFont(font);
    message.setColor(sf::Color::White);
    message.setString(text);
    message.setPosition(0, 50);
  }

}


//Drawing
void Help::draw(sf::RenderWindow &window)
{
  window.draw(bk);              //Draw bk
  InputManager::getInstance()->draw(window);
  window.draw(message);         //Draw message

}