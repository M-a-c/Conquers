#pragma once 
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Failure.hpp"
#include "Scenes.cpp"
#include "Button.hpp"
#include "ButtonManager.hpp"
#include "InputManager.hpp"

using std::string;

class Help:public Scene
{

public:
  //Constructor and deconstructor
  Help(sf::RenderWindow &window, int &re_val);
  ~Help();
private:
  //Screen Updaters
  void draw(sf::RenderWindow &window);
  int update(sf::RenderWindow &window);
  void getImage(float width, float height);

  //Button Handlers
  int returnPress(){ return selectedItem; };

  //Selected item Index
  int selectedItem;

  //Text
  string text;
  sf::Font font;
  sf::Text message;

  //Button
  sf::Texture texture[2];
  Button button[2];

};