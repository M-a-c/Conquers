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
		InputManager::getInstance()->update(window,event);
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
          button[3].checkHover(event.mouseMove.x, event.mouseMove.y);
          break;

        //Click button
        case::sf::Event::MouseButtonReleased:
          if (button[0].mouseClicked() == true)
          {
            std::cout << "Login\n";
            return 1;
          }
          else if (button[1].mouseClicked() == true)
          {
            std::cout << "New\n";
            return 2;
          }
          else if (button[2].mouseClicked() == true)
          {
            std::cout << "Help\n";
            return 3;
          }
          else if (button[3].mouseClicked() == true)
          {
            std::cout << "Exit\n";
            window.close();
            exit(0);
          }
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

  for (int i = 0; i < 4; i++)
    window.draw(button[i]);

}

//Handler for hitting the down key
void MainMenu::moveDown()
{
  if (selectedItem + 1 < 4)
  {
   
    button[selectedItem].animateDown();
    selectedItem++;
    button[selectedItem].animateUp();
    button[selectedItem].sound_hover.play();

  }

}

//Handler for hitting the up key
void MainMenu::moveUp()
{
  if (selectedItem - 1 >= 0)
  {

    button[selectedItem].animateDown();
    selectedItem--;
    button[selectedItem].animateUp();
    button[selectedItem].sound_hover.play();
  }
}

//Function thta will load images
void MainMenu::getImage(float width, float height)
{
  //Getting the images
  if (!texture_buttons[0].loadFromFile("images/b_login.png", sf::IntRect(0, 0, 180, 60)))
    imageFail_important("images/b_login.png");
  if (!texture_buttons[1].loadFromFile("images/b_createAcc.png", sf::IntRect(0, 0, 456, 60)))
    imageFail_important("images/b_createAcc.jpg");
  if (!texture_buttons[2].loadFromFile("images/b_help.png", sf::IntRect(0, 0, 180, 60)))
    imageFail_important("images/b_help.png");
  if (!texture_buttons[3].loadFromFile("images/b_exit.png", sf::IntRect(0, 0, 180, 60)))
    imageFail_important("images/b_exit.png");

  if (!texture_title.loadFromFile("images/title_1.png"))
    imageFail_important("images/title_1.png");


  //Loading into sprites and setting position
  //Login
  button[0].setTexture(texture_buttons[0]);
  button[0].setPosition(sf::Vector2f( (width / 2)-(180/2), (height / 2)));
  button[0].setScale(1.15f, 1.15f);

  //Create Account Button
  button[1].setTexture(texture_buttons[1]);
  button[1].setPosition(sf::Vector2f((width / 2) - (456 / 2), (height / 2) + 70));

  //Help Button
  button[2].setTexture(texture_buttons[2]);
  button[2].setPosition(sf::Vector2f((width / 2) - (180 / 2), (height / 2) + 140));

  //Exit button
  button[3].setTexture(texture_buttons[3]);
  button[3].setPosition(sf::Vector2f((width / 2) - (180 / 2), (height / 2) + 210));

  //Loading title
  sprite_title.setTexture(texture_title);
  sprite_title.setPosition(sf::Vector2f((width / 2) - (sprite_title.getGlobalBounds().width / 2), height / 5) );
}
