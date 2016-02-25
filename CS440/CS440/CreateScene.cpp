#include "CreateScene.hpp"

//Helping constuctor
Create::Create(sf::RenderWindow &window, int &re_val)
{
  name = "Create";      //set name
  setBackground("images/menu_image3.jpg");    //Set background
  getImage((float)window.getSize().x,         //Load buttons
    (float)window.getSize().y);
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
      case::sf::Event::MouseButtonReleased:
        if (button[0].mouseClicked() == true)
        {
          std::cout << "Create\n";
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
            std::cout << "Create\n";
            //TODO//
          }
          else if (returnPress() == 1)
          {
            std::cout << "Back\n";
            return 0;
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
    userName_text.setColor(sf::Color::White);
    userName_text.setString("Enter USERNAME:");
    userName_text.setPosition(50, 50);

    //Message::No draw yet
    message.setFont(font);
    message.setColor(sf::Color::White);
    message.setString(" ");
    message.setPosition(50, 50);

    //password label
    password_text.setFont(font);
    password_text.setColor(sf::Color::White);
    password_text.setString("Enter PASSWORD:");
    password_text.setPosition(50, 100);
  }


  //Getting the images
  if (!texture[0].loadFromFile("images/buttons2.png", sf::IntRect(45, 135, 219, 37)))
    imageFail_important("images/menu_image3.jpg");
  if (!texture[1].loadFromFile("images/menu_buttons.png", sf::IntRect(45, 210, 219, 40)))
    imageFail_important("images/menu_image3.jpg");
  

  //Create Login Button
  button[0].setTexture(texture[0]);
  button[0].setPosition(sf::Vector2f((width / 4) - (215 / 2), height - 100));
  button[0].setScale(1.15f, 1.15f);
  //Create Create Button
  button[1].setTexture(texture[1]);
  button[1].setPosition(sf::Vector2f(((width / 4) * 2) - (215 / 2), height - 100));

}


//Drawing
void Create::draw(sf::RenderWindow &window)
{
  window.draw(bk);              //Draw bk
  for (int i = 0; i < 2; i++)   //Drawing button
    window.draw(button[i]);
  window.draw(password_text);   //Draw password prompt
  window.draw(userName_text);   //Draw username prompt

}


//Handler for Right
void Create::moveRight()
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
void Create::moveLeft()
{
  if (selectedItem - 1 >= 0)
  {
    button[selectedItem].animateDown();       //No animation
    selectedItem--;                           //next button
    button[selectedItem].animateUp();         //Animation
    button[selectedItem].sound_hover.play();  //Sound
  }
}