#pragma once
#include <SFML/Graphics.hpp>
#include "Failure.hpp"
#include "Scenes.cpp"
#include "Button.hpp"
#include <iostream>
#include <string>
#include "Failure.hpp"
#include "InputManager.hpp"
#include "RunningData.hpp"

using std::string;

class GameOptions :public Scene
{
public:
  GameOptions(sf::RenderWindow &window, int &re_val);
  ~GameOptions();
private:
  //Screen Updaters
  void draw(sf::RenderWindow &window);
  int update(sf::RenderWindow &window);
  void getImage(float width, float height);
  char isTypableText(sf::Keyboard::Key);

  void buttonSelectionCheck();

  //Options the user selected for game
  int selectedColor;
  int selectedTime;
  int selectedDur;
  int selectedEra;
  int selectedUnits;

  sf::Texture texture[21];
  Button button[13];
  Button opButton[2];
  Button sword[5];
  Button prompt[5];

};