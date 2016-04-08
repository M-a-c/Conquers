#pragma once 
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Failure.hpp"
#include "Scenes.cpp"
#include "Button.hpp"
#include "StringInput.hpp"
#include "RunningData.hpp"

using std::string;

class Login :public Scene
{

public:
  //Constructor and deconstructor
  Login(sf::RenderWindow &window, int &re_val);
  ~Login();
private:
  //Screen Updaters
  void draw(sf::RenderWindow &window);
  int update(sf::RenderWindow &window);
  void getImage(float width, float height);
  char isTypableText(sf::Keyboard::Key);

  //Button Handlers
  int returnPress(){ return selectedItem; };

  //Selected item Index
  int selectedItem;

  //Button
  sf::Texture texture[3];
  Button button[3];

  //Prompt
  sf::Font font;
  sf::Text userName_text;
  sf::Text password_text;

  bool EnteringPassword;

  std::string usernameString;
  std::string passwordString;
  std::string passwordStringOBF;


};