#include "ConquerScene.hpp"

Conquer::Conquer(sf::RenderWindow &window,Player &player1,Ai &player2)
{
  //Setting game variables
  name = "Conquer";
  setBackground("images/scene_image.jpg");
  int part = 1;

}

Conquer::~Conquer()
{
  std::cout << "Deconstructor for Gameplay" << std::endl;
}

void Conquer::draw(sf::RenderWindow &window)
{
  window.draw(bk);
 
  if (part)
    drawButtons(window,1);
  else
    drawButtons(window,2);
  


}

int Conquer::update(sf::RenderWindow &window)
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

        //Mouse over button
      case sf::Event::MouseMoved:
        mouseHoverEvent(event);
        break;

      case sf::Event::MouseButtonReleased:
        clickEvents();
        break;

      }
    }

    //Clearing and drawing
    window.clear();
    draw(window);
    window.display();

  }
  return 0;
}

void Conquer::getImage(float width, float height)
{

  //Loading Font
  if (!font.loadFromFile("arial.ttf"))
  {
    fontFail("arial.tff");
  }
  else
  {
    //username lable
    story.setFont(font);
    story.setColor(sf::Color::White);
    question.setFont(font);
    question.setColor(sf::Color::White);
    stats.setFont(font);
    stats.setColor(sf::Color::White);


  }

  if (!texture[0].loadFromFile("images/A.png", sf::IntRect(0, 0, 51, 40)))
    imageFail_important("images/A.png");
  if (!texture[1].loadFromFile("images/C.png", sf::IntRect(0, 0, 50, 40)))
    imageFail_important("images/C.png");
  if (!texture[2].loadFromFile("images/B.png", sf::IntRect(0, 0, 51, 40)))
    imageFail_important("images/B.png");
  if (!texture[3].loadFromFile("images/attack.png", sf::IntRect(0, 0, 100, 40)))
    imageFail_important("images/attack.png");
  if (!texture[4].loadFromFile("images/retreat.png", sf::IntRect(0, 0, 100, 40)))
    imageFail_important("images/retreat.png");
  if (!texture[5].loadFromFile("images/Choose.png", sf::IntRect(0, 0, 200, 60)))
    imageFail_important("images/Choose.png");
  if (!texture[6].loadFromFile("images/b_next.png", sf::IntRect(0, 0, 180, 60)));
    imageFail_important("images/b_next.png");

  a.setTexture(texture[0]);
  b.setTexture(texture[1]);
  c.setTexture(texture[2]);
  attack.setTexture(texture[3]);
  retreat.setTexture(texture[4]);
  label.setTexture(texture[5]);

 
}

//TODO
void Conquer::loadStory()
{
  
}

void Conquer::mouseHoverEvent(sf::Event event)
{
  a.checkHover(event.mouseMove.x, event.mouseMove.y);
  b.checkHover(event.mouseMove.x, event.mouseMove.y);
  c.checkHover(event.mouseMove.x, event.mouseMove.y);
  attack.checkHover(event.mouseMove.x, event.mouseMove.y);
  retreat.checkHover(event.mouseMove.x, event.mouseMove.y);
}

void Conquer::clickEvents()
{
  

}

void Conquer::drawButtons(sf::RenderWindow &window,int index)
{
  if (index == 1)
  {
    window.draw(a);
    window.draw(b);
  }
}