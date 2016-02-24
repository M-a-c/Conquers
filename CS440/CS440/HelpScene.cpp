#include "HelpScene.hpp"

Help::Help(sf::RenderWindow &window, int &re_val)
{
  name = "Help";
  text = "Welcome to the help screen, There will be pleanty of magic here soon.\n BTW hit ESC key to go back";
  setBackground("images/menu_image3.jpg");
  getImage((float)window.getSize().x,
    (float)window.getSize().y);
  re_val = update(window);
  return;

}

Help::~Help()
{
  std::cout << "Deconstructor for Help" << std::endl;
}

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

        //Button Event
      case sf::Event::KeyReleased:
        switch (event.key.code)
        {
          //Esc
        case sf::Keyboard::Escape:
          return 0;
          break;
        }break;

      }
    }
      
    window.clear();
    draw(window);
    window.display();
    
  }
  return 0;
}

void Help::getImage(float width, float height)
{

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

void Help::draw(sf::RenderWindow &window)
{
  window.draw(bk);
  window.draw(message);
}