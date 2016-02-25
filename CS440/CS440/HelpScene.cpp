#include "HelpScene.hpp"

//Helping constuctor
Help::Help(sf::RenderWindow &window, int &re_val)
{
  name = "Help";      //set name
  text = "Welcome to the help screen, There will be pleanty of magic here soon.\n BTW hit Back  to go back";    //Message
  setBackground("images/menu_image3.jpg");    //Set background
  getImage((float)window.getSize().x,         //Load buttons
    (float)window.getSize().y);
  selectedItem = 0;                           //Selected item index
  re_val = update(window);                    //update and next scene
  return;                                     //return

}

Help::~Help()
{
  std::cout << "Deconstructor for Help" << std::endl;
}


//Update loop
int Help::update(sf::RenderWindow &window)
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
      case::sf::Event::MouseButtonReleased:
        if (button[0].mouseClicked() == true)
        {
          std::cout << "Back\n";
          return 0;
        }
        else if (button[1].mouseClicked() == true)
        {
          std::cout << "Next\n";
          //TODO//
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

        //W button
        case sf::Keyboard::D:
          moveRight();
          break;

        //S button
        case sf::Keyboard::A:
          moveLeft();
          break;

        //Return button
        case sf::Keyboard::Return:
          if (returnPress() == 0)
          {
            std::cout << "Back\n";
            return 0;
          }
          else if (returnPress() == 1)
          {
            std::cout << "Next\n";
          }
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

  //Getting the images
  if (!texture[0].loadFromFile("images/b_back.png", sf::IntRect(0, 0, 180, 60)))
    imageFail_important("images/b_back.jpg");
  if (!texture[1].loadFromFile("images/b_next.png", sf::IntRect(0, 0, 180, 60)))
    imageFail_important("images/b_next.jpg");

  //Create Back Button
  button[0].setTexture(texture[0]);
  button[0].setPosition(sf::Vector2f((width / 4) - (180 / 2), (height / 8) * 6));
  button[0].setScale(1.15f, 1.15f);

  //Create Next Button
  button[1].setTexture(texture[1]);
  button[1].setPosition(sf::Vector2f(((width / 4) * 3) - (180 / 2), (height / 8) * 6));


}


//Drawing
void Help::draw(sf::RenderWindow &window)
{
  window.draw(bk);              //Draw bk
  for (int i = 0; i < 2; i++)   //Drawing button
    window.draw(button[i]);
  window.draw(message);         //Draw message

}


//Handler for Right
void Help::moveRight()
{
  if (selectedItem + 1 < 2)
  {
    button[selectedItem].animateDown();       //No animation
    selectedItem++;                           //next button
    button[selectedItem].animateUp();         //Animation
    button[selectedItem].sound_hover.play();  //Sound
  }
}


//Handler for Left
void Help::moveLeft()
{
  if (selectedItem - 1 >= 0)
  {
    button[selectedItem].animateDown();       //No animation
    selectedItem--;                           //next button
    button[selectedItem].animateUp();         //Animation
    button[selectedItem].sound_hover.play();  //Sound
  }
}