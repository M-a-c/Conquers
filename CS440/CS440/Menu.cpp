#include "Menu.h"
#include <iostream>

Menu::Menu(float width, float height)
{

  if (!font.loadFromFile("arial.ttf"))
  {
    
    //Error 
  }

  menuItem[0].setFont(font);
  menuItem[0].setColor(sf::Color::Blue);
  menuItem[0].setString("Login"); 
  menuItem[0].setPosition(sf::Vector2f(width / 3, height / (4+1) * 1));

  menuItem[1].setFont(font);
  menuItem[1].setColor(sf::Color::White);
  menuItem[1].setString("Create");
  menuItem[1].setPosition(sf::Vector2f(width / 3, height / (4 + 1) * 2));

  menuItem[2].setFont(font);
  menuItem[2].setColor(sf::Color::White);
  menuItem[2].setString("Help");
  menuItem[2].setPosition(sf::Vector2f(width / 3, height / (4 + 1) * 3));

  menuItem[3].setFont(font);
  menuItem[3].setColor(sf::Color::White);
  menuItem[3].setString("Exit");
  menuItem[3].setPosition(sf::Vector2f(width / 3, height / (4 + 1) * 4));

  selectedItem = 0;


}

void Menu::W_ButtonPress()
{
  if (selectedItem - 1 >= 0)
  {
    menuItem[selectedItem].setColor(sf::Color::White);
    selectedItem--;
    menuItem[selectedItem].setColor(sf::Color::Blue);
  }

}

void Menu::S_ButtonPress()
{
  if (selectedItem + 1 < 4)
  {
    menuItem[selectedItem].setColor(sf::Color::White);
    selectedItem++;
    menuItem[selectedItem].setColor(sf::Color::Blue);
  }
}


Menu::~Menu()
{
  std::cout << "Deconstrcutor for Menu\n";
}


void Menu::draw(sf::RenderWindow &window)
{
  for (int i = 0; i < 4; i++)
    window.draw(menuItem[i]);
}

