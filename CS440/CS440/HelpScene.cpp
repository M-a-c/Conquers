#include "HelpScene.hpp"

//Helping constuctor
Help::Help(sf::RenderWindow &window, int &re_val)
{
  name = "Help";      //set name
  text = "Welcome to the conquerors game. To begin playing first create an account. If you already have\n an account login and play."
	  " When creating you will be given a screen to choose you prefered\n"
	  "color(red or green).Then choose an era. Then for time choose how long the total game will last. Duration means\n"
	  "how long the round will last. Units gives the players different starting units.\n\n"
	  "Rules::\n"
	  "Gold increase by workers every 10 secs. Add workers add a worker at the cost of 20 gold\n"
	  "You cannot add more then the limit. Same things with militart units(siege,cavalry,infantry)\n"
	  "Cost:: siege - 125 cavalry-50 infantry-20.\n"
	  "Adding is done through the add button.Conquer begins attack on the other player./n"
	  "Then you will be given a history and questions for each question answered correctly\n"
	  "you recieve some knowledge about opponent. Then you can choose not to fight or fight.\n"
	  "End turn allows you to end the turn and switches over to other player. Save and quit\n"
	  "Will save and exit the game.";

  text2 = "Good luck. Have fun. And destory some fools\n\n\n";

  setBackground("images/menu_image3.jpg");    //Set background
 

  float width = (float)window.getSize().x;
  float height = (float)window.getSize().y;

  ButtonManager::getInstance()->addButton(new Button(None, "Back", "images/b_back.png", sf::IntRect(0, 0, 180, 60), sf::Vector2f((width / 4) - (180 / 2), (height / 8) * 6)));
  //ButtonManager::getInstance()->addButton(new Button(CreateScene, "Create", "images/b_next.png", sf::IntRect(0, 0, 180, 60), sf::Vector2f(((width / 4) * 3) - (180 / 2), (height / 8) * 6)));

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


//Drawing
void Help::draw(sf::RenderWindow &window)
{
  window.draw(bk);              //Draw bk
  InputManager::getInstance()->draw(window);
  window.draw(message);         //Draw message

}