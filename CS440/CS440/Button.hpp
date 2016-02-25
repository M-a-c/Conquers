#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Failure.hpp"

class Button:public sf::Sprite,public Failure
{
public:
  Button();   //Nothing Here
  ~Button();  //Deconstuctor
  void checkHover(int mX,int mY);   //Checks if the mouse is over the button 
  bool mouseClicked();    //Checking if mouse is clicked on valid button
  void animateUp();       //Animate when hovering
  void animateDown();     //No animation 
  sf::Sound sound_hover;  //hover sound


private:
  bool mouseOver;         //boolean to check if mouse if over button
  sf::SoundBuffer buffer_hover; //Sound buffer
  bool playOnce;  //checks to see if sound has been played once

};
#endif