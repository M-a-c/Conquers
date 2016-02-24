#pragma once 
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Failure.hpp"
#include "Scenes.cpp"
using std::string;

class Help:public Scene
{

public:
  Help(sf::RenderWindow &window, int &re_val);
  ~Help();
private:
  //Screen Updaters
  void draw(sf::RenderWindow &window);
  int update(sf::RenderWindow &window);
  void getImage(float width, float height);

  //Text
  string text;
  sf::Font font;
  sf::Text message;

};