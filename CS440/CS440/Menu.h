#pragma once
#include "SFML/Graphics.hpp"

class Menu{
public:
  Menu(float width, float height);
  ~Menu();

  void draw(sf::RenderWindow &window);
  void W_ButtonPress();
  void S_ButtonPress();
  int getEnterPress(){ return selectedItem; }


private:
  int selectedItem;
  sf::Font font;
  sf::Text menuItem[4];



};