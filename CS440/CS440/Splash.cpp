#include "Splash.hpp"

Splash::Splash(sf::RenderWindow &window, int &re_val)
{
 
  //Setting screen size
  scr_height = window.getSize().y;
  scr_width = window.getSize().x;
  setBackground("images/Splash_bk.png");
  bk.setPosition(-100, 0);

  getImage(scr_width, scr_height);       //Load images

  //init values
  isMoveRight == false;
  isMoveLeft == false;
  isJump == false;
  jumpIndex = 0;

  if (isMoveRight == false)
  {
    //set sprite rectangle position
    source.x = 32;
    source.y = 2;
    isMoveRight == true;
  }

  
  re_val = update(window);

}

Splash::~Splash()
{
  std::cout << "Doconstuctor for Splash" << std::endl;
}

void Splash::getImage(float width, float height)
{
  if (!animation_texture.loadFromFile("images/monkey.png", sf::IntRect(0, 0, 384, 256)))
    imageFail_important("images/monkey.png");

  monkey_spr.setTexture(animation_texture);
 
  monkey_spr.setPosition(32, 500);
  monkey_spr.setScale(4.0f, 4.0f);


  
}

int Splash::update(sf::RenderWindow &window)
{
  while (window.isOpen())
  {
    sf::Event event;

    //Look for event
    while (window.pollEvent(event)){

      //inputManager->update(window, event);
      switch (event.type)
      {
        //Event for hitting the x
      case sf::Event::Closed:
        window.close();
        exit(0);
        break;

      }
    }

    monkeyActions();

    //Check is splash timer is over
    if (splashTimer.getElapsedTime() > maxTime)
      return 0;

    window.clear();
    draw(window);
    window.display();

  }
  return 0;
}

//Making the monkey animated
void Splash::monkeyActions()
{
  //Less than 4 seconds move monkey is moving right
  if ((splashTimer.getElapsedTime().asSeconds() < 4))
  {
    moveRightMK();
  }
  //Between 4 an 8 sec monkey jumps
  else if ((splashTimer.getElapsedTime().asSeconds() > 4) && (splashTimer.getElapsedTime().asSeconds() < 8))
  {
    jumpMK();
  }
  //After 8 sec to 15 move left
  else
  {
    moveLeftMK();
  }

  //Get sprite rectangle
  monkey_spr.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, 32, 32));
}


//Move left monkey
void Splash::moveLeftMK()
{

  //If it hasn't move left
  if (isMoveLeft == false)
  {
    //set sprite rectangle position 
    source.x = 32;
    source.y = 1;
    isMoveLeft = true;
  }

  //Every .1 of sec change sprite
  if (aniTimer.getElapsedTime().asSeconds() > .07f)
  {
    source.x++;
    aniTimer.restart();
  }

  //Move the monkey left
  monkey_spr.move(-.5, 0);

  //Off sprite sheet reset to start
  if (source.x * 32 >= 32 * 3)
    source.x = 0;
}


//Move right Monkey
void Splash::moveRightMK()
{

  //Changing sprite every .7 sec
  if (aniTimer.getElapsedTime().asSeconds() > .07f)
  {
    source.x++;
    aniTimer.restart();
  }

  //Moving the monkey
  monkey_spr.move(.5, 0);

  //If sprite off sheet reset
  if (source.x * 32 >= 32 * 3)
    source.x = 0;
}

void Splash::jumpMK()
{
  //If monkey hasnt jumped
  if (isJump == false)
  {
      //set sprite rectangle position 
      source.x = 5;
      source.y = 0;
      isJump = true;
  }

  //If monkey hasn't jumped
  if (jumpIndex < 4)
  {
    //Move monkey up
    if (aniTimer.getElapsedTime().asSeconds() < .5f)
    {
      monkey_spr.move(0, -.2);
    }
    //Move monkey down
    else if (aniTimer.getElapsedTime().asSeconds() > .5f && aniTimer.getElapsedTime().asSeconds() < 1.0f)
    {
      monkey_spr.move(0, .2);
      
    }
    else if (aniTimer.getElapsedTime().asSeconds() > 1.0f)
    {
      aniTimer.restart();
      isJump++;
    }

  }
  



}

void Splash::draw(sf::RenderWindow &window)
{
  window.draw(bk);
  window.draw(monkey_spr);

}