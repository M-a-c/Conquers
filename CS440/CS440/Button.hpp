#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Failure.hpp"

enum GameScene
{
	None,
	OptionsScene,
	HelpScene,
	LoginScene,
	Exit,
	CreateScene,
	MainMenuScene
};

class Button :public sf::Sprite, public Failure{
public:
  Button();   //Nothing Here
  Button(GameScene);   //Nothing Here
  Button(GameScene,sf::Vector2f);   //Nothing Here
  ~Button();  //Deconstuctor
  void checkHover(int mX,int mY);   //Checks if the mouse is over the button 
  void checkHover(sf::Event event);   //Checks if the mouse is over the button takes an event instead
  bool mouseClicked();    //Checking if mouse is clicked on valid button
  void animateUp();       //Animate when hovering
  void animateDown();     //No animation 
  sf::Sound sound_hover;  //hover sound
  bool Button::loadFromFile(string file, sf::IntRect rect);
  bool Button::setTexture(string file, sf::IntRect rect);
  void Button::setTexture(sf::Texture t);
  GameScene Scene;

  string actionString;//A string that describes what aciton the button preformed.

private:
  bool mouseOver;         //boolean to check if mouse if over button
  sf::SoundBuffer buffer_hover; //Sound buffer
  bool playOnce;  //checks to see if sound has been played once
  sf::Texture texture;// the texture displayed as the button.

};
#endif