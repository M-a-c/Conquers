#include "Button.hpp"

//Nothing here
Button::Button()
{
  //Loading sound file
  if (!buffer_hover.loadFromFile("Sound/hover_sound.wav"))
    soundFail("Sound/hover_sound.wav");
  else
    sound_hover.setBuffer(buffer_hover);

  //Set to false
  playOnce = false;
}


//Deconstrcutor message
Button::~Button()
{
  std::cout << "Deconstrcutor for Buttons" << std::endl;
}


//Mouse clicked and vlaid
bool Button::mouseClicked()
{
  if (mouseOver)
  {
    return true;
  }
  return false;
}

//Mouse hovering over button
void Button::checkHover(int mX, int mY)
{
  //Mouse bounds check
  if (getPosition().x < mX && getPosition().y < mY && (getGlobalBounds().width + getPosition().x) > mX && (getGlobalBounds().height + getPosition().y) > mY)
  {
    animateUp();      //Animate up
    mouseOver = true; //Hover to true
  }
  else
  {
    animateDown();    //No animation 
    mouseOver = false;//No mouse over
  }
}


//Animation by scale and play sound
void Button::animateUp()
{
  if (playOnce == false)  //Play sound
    sound_hover.play();

  setScale(1.15f, 1.15f);

  playOnce = true;
}


//No animation
void Button::animateDown()
{
  setScale(1, 1);
  playOnce = false;
}
