#pragma once
#include "SFML\Graphics.hpp"
#include "Failure.hpp"
#include "Scenes.cpp"
#include "Button.hpp"


class MainMenu : public Scene
{
public:
  MainMenu(sf::RenderWindow &window, int &re_val);
  ~MainMenu();
private:
  //Button Handlers
  void moveUp();
  void moveDown();
  int returnPress(){ return selectedItem; };

  //Screen Updaters
  void draw(sf::RenderWindow &window);
  int update(sf::RenderWindow &window);
  void getImage(float width, float height);
  
  //Selected item Index
  int selectedItem;  

  //Images
  sf::Texture texture_buttons[4];
  sf::Texture texture_title;
  sf::Sprite sprite_title;
  Button button[4];
};