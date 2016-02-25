#pragma once 
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Failure.hpp"
#include "Scenes.cpp"
#include "Button.hpp"

using std::string;

class Create:public Scene
{

public:
  //Constructor and deconstructor
  Create(sf::RenderWindow &window, int &re_val);
  ~Create();
private:
  //Screen Updaters
  void draw(sf::RenderWindow &window);
  int update(sf::RenderWindow &window);
  void getImage(float width, float height);

  //Button Handlers
  void moveRight();
  void moveLeft();
  int returnPress(){ return selectedItem; };

  //Selected item Index
  int selectedItem;

  //Button
  sf::Texture texture[2];
  Button button[2];

  //Prompt
  sf::Font font;
  sf::Text userName_text;
  sf::Text password_text;
  sf::Text message;

};