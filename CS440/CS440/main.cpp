#include <SFML/Graphics.hpp>
#include "Menu.h"
#include <iostream>


int main()
{
  sf::RenderWindow window(sf::VideoMode(1200, 600), "My Ghetto Rig Menu!");

  Menu menu(window.getSize().x, window.getSize().y);


  while (window.isOpen())
  {
    sf::Event event;

    while (window.pollEvent(event))
    {

      switch (event.type)
      {
        case sf::Event::Closed:
          window.close();break;
        
        case sf::Event::KeyReleased:
          switch (event.key.code)
          {
            case sf::Keyboard::Up:
              menu.W_ButtonPress(); break;
            case sf::Keyboard::Down:
              menu.S_ButtonPress(); break;
            case sf::Keyboard::Return:
              if (menu.getEnterPress() == 0)
              {
                std::cout << "Login\n";
              }
              else if (menu.getEnterPress() == 1)
              {
                std::cout << "New\n";
              }
              else if (menu.getEnterPress() == 2)
              {
                std::cout << "Help\n";
              }
              else if (menu.getEnterPress() == 3)
              {
                std::cout << "Exit\n";
                window.close();
              }
                
          }

      }

    }

    window.clear();

    menu.draw(window);

    window.display();
  }

  return 0;
}