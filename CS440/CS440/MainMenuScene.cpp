#include "MainMenuScene.hpp"

MainMenu::MainMenu(sf::RenderWindow &window,int &re_val)
{
  name = "Main Menu ";                        //Set name
  setBackground("images/menu_image3.jpg");    //Load background
  getImage((float)window.getSize().x,
    (float)window.getSize().y);               //Get screen size


  float width = window.getSize().x;
  float height = window.getSize().y;
  selectedItem = 0;                           //Selected item index

  ButtonManager::getInstance()->addButton(new Button(LoginScene, "Login", "images/b_login.png", sf::IntRect(0, 0, 180, 60), sf::Vector2f((width / 2) - (180 / 2), (height / 2))) );
  ButtonManager::getInstance()->addButton(new Button(CreateScene, "Create", "images/b_createAcc.png", sf::IntRect(0, 0, 456, 60), sf::Vector2f((width / 2) - (456 / 2), (height / 2) + 70))) ;
  ButtonManager::getInstance()->addButton(new Button(HelpScene, "Help", "images/b_help.png", sf::IntRect(0, 0, 180, 60), sf::Vector2f((width / 2) - (180 / 2), (height / 2) + 140))) ;
  ButtonManager::getInstance()->addButton(new Button(Exit, "Exit", "images/b_exit.png", sf::IntRect(0, 0, 180, 60), sf::Vector2f((width / 2) - (180 / 2), (height / 2) + 210))) ;

  RunningData::getInstance()->reset();

  re_val = update(window);                    //update loop with return value
  return;                                     //return from MainMenu
}

//Deconstructor
MainMenu::~MainMenu()
{
	ButtonManager::getInstance()->removeAllButtons();
	std::cout << "Deconstructor for Main Menu" << std::endl;
}

//Updating the loop
int MainMenu::update(sf::RenderWindow &window)
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

//Drawing images and things
void MainMenu::draw(sf::RenderWindow &window)
{
  window.draw(bk);
  window.draw(sprite_title);
  InputManager::getInstance()->draw(window);

}


//Function thta will load images
void MainMenu::getImage(float width, float height)
{


  if (!texture_title.loadFromFile("images/title_1.png"))
    imageFail_important("images/title_1.png");

  sprite_title.setTexture(texture_title);
  sprite_title.setPosition(sf::Vector2f((width / 2) - (sprite_title.getGlobalBounds().width / 2), height / 5) );
}
