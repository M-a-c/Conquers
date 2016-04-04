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

//Mouse hovering over button using just an event.
// would move this stuff up into the button manager class when we can. ie, just the if statement.
void Button::checkHover(sf::Event event)
{
	if (event.type == sf::Event::MouseMoved){
		int mX = event.mouseMove.x;
		int mY = event.mouseMove.y;
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

bool Button::loadFromFile(string file, sf::IntRect rect){
	setTexture(file, rect);
}


bool Button::setTexture(string file, sf::IntRect rect){
	if (!this->texture.loadFromFile(file, rect)){
		Failure::imageFail_important(file);
	}
	else{
		this->sf::Sprite::setTexture(texture);
		return 1;
	}
}

void Button::setTexture(sf::Texture t){
	texture = t;
	this->sf::Sprite::setTexture(texture);
}
