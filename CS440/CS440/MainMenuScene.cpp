#include "MainMenuScene.hpp"

MainMenu::MainMenu(sf::RenderWindow &window,int &re_val)
{
  name = "Main Menu ";                        //Set name
  setBackground("images/menu_image3.jpg");    //Load background
  getImage((float)window.getSize().x,
    (float)window.getSize().y);               //Get screen size
  selectedItem = 0;                           //Selected item index
  re_val = update(window);                    //update loop with return value
  return;                                     //return from MainMenu
}

//Deconstructor
MainMenu::~MainMenu()
{
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

      switch (event.type)
      {
        //Event for hitting the x
        case sf::Event::Closed:
          window.close(); 
          exit(0); 
          break;
        
        //Button Event
        case sf::Event::KeyReleased:
          switch (event.key.code)
          {
            //Up arrow
            case sf::Keyboard::Up:
             moveUp(); 
             break;

            //Down arrow
            case sf::Keyboard::Down:
              moveDown(); 
              break;

            //W button
            case sf::Keyboard::W:
              moveUp();
              break;

            //S button
            case sf::Keyboard::S:
              moveDown();
              break;

            //Return button
            case sf::Keyboard::Return:
              if (returnPress() == 0)
              {
                std::cout << "Login\n";
                return 1;
              }
              else if (returnPress() == 1)
              {
                std::cout << "New\n";
                return 2;
              }
              else if (returnPress() == 2)
              {
                std::cout << "Help\n";
                return 3;
              }
              else if (returnPress() == 3)
              {
                std::cout << "Exit\n";
                window.close();
                exit(0);
              }

          }
          break;

      }

    }

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
  for (int i = 0; i < 4; i++)
    window.draw(sprite_buttons[i]);

}

//Handler for hitting the down key
void MainMenu::moveDown()
{
  if (selectedItem + 1 < 4)
  {
    //Change scaling
    sprite_buttons[selectedItem].setScale(1, 1);
    selectedItem++;
    sprite_buttons[selectedItem].setScale(1.15f, 1.15f);
  }

}

//Handler for hitting the up key
void MainMenu::moveUp()
{
  if (selectedItem - 1 >= 0)
  {
    //Change scaling
    sprite_buttons[selectedItem].setScale(1, 1);
    selectedItem--;
    sprite_buttons[selectedItem].setScale(1.15f, 1.15f);
  }
}

//Function thta will load images
void MainMenu::getImage(float width, float height)
{
  //Getting the images
  if (!texture_buttons[0].loadFromFile("images/menu_buttons.png", sf::IntRect(45, 135, 215, 37)))
    imageFail_important("images/menu_image3.jpg");
  if (!texture_buttons[1].loadFromFile("images/menu_buttons.png", sf::IntRect(45, 210, 215, 40)))
    imageFail_important("images/menu_image3.jpg");
  if (!texture_buttons[3].loadFromFile("images/menu_buttons.png", sf::IntRect(45, 370, 215, 40)))
    imageFail_important("images/menu_image3.jpg");
  if (!texture_buttons[2].loadFromFile("images/menu_buttons.png", sf::IntRect(45, 290, 215, 40)))
    imageFail_important("images/menu_image3.jpg");
  if (!texture_title.loadFromFile("images/title_3.png"))
    imageFail_important("images/title_3.png");


  //Loading into sprites and setting position
  //Login
  sprite_buttons[0].setTexture(texture_buttons[0]);
  sprite_buttons[0].setPosition(sf::Vector2f(0, (height / 2)));
  sprite_buttons[0].setScale(1.15f, 1.15f);

  //Create Account Button
  sprite_buttons[1].setTexture(texture_buttons[1]);
  sprite_buttons[1].setPosition(sf::Vector2f(0, (height / 2) + 50));

  //Help Button
  sprite_buttons[2].setTexture(texture_buttons[2]);
  sprite_buttons[2].setPosition(sf::Vector2f(0, (height / 2) + 100));

  //Exit button
  sprite_buttons[3].setTexture(texture_buttons[3]);
  sprite_buttons[3].setPosition(sf::Vector2f(0, (height / 2) + 150));

  //Loading title
  sprite_title.setTexture(texture_title);
  sprite_title.setPosition(sf::Vector2f(0, height / 5));
}
