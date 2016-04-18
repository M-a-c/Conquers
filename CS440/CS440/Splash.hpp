#pragma once
#include "Scenes.cpp"
#include <iostream>
#include <string>
#include "InputManager.hpp"
#include "Failure.hpp"
#include <SFML/Graphics.hpp>

class Splash : public Scene
{
public:
  //Images
  sf::Texture animation_texture;

  sf::Sprite monkey_spr;

  //Boolean for monkey movement
  bool isMoveRight;
  bool isJump;
  bool isMoveLeft;

  //Screen Info
  int scr_width;
  int scr_height;

  //Hom many time jump
  int jumpIndex;

  //Rectangle position on texture
  sf::Vector2i source;

  //Splash Timer
  const sf::Time maxTime =sf::seconds(15);
  sf::Clock splashTimer;

  //Monkey Timer
  sf::Clock aniTimer;

  //Constructor and deconstructor
  Splash(sf::RenderWindow &window, int &re_val);
  ~Splash();

private:
  //Drawing and updating
  void getImage(float width, float height);
  int update(sf::RenderWindow & window);
  void draw(sf::RenderWindow & window);

  void monkeyActions();
  void moveRightMK();
  void moveLeftMK();
  void jumpMK();

};
