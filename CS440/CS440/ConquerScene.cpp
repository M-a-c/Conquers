#include "ConquerScene.hpp"

Conquer::Conquer(sf::RenderWindow &window,Player &player1,Ai &player2)
{
  //Setting game variables
  name = "Conquer";
  setBackground("images/scene_image.jpg");  //set background
  getImage((float)window.getSize().x,       //Load images
    (float)window.getSize().y);

  //Set sections and other info
  x = window.getSize().x;
  y = window.getSize().y;
  q = 0;


  if (RunningData::getInstance()->mapFile[0] != 'w'){ q = 1; }
  if (RunningData::getInstance()->mapFile[1] != 'w'){ q = 2; }
  if (RunningData::getInstance()->mapFile[2] != 'w'){ q = 3; }
  if (RunningData::getInstance()->mapFile[3] != 'w'){ q = 0; 
	  //Reset so we dont break the game :d
  RunningData::getInstance()->mapFile[0] = 'w';
  RunningData::getInstance()->mapFile[1] = 'w';
  RunningData::getInstance()->mapFile[2] = 'w';
  RunningData::getInstance()->mapFile[3] = 'w';
  }


  part = 1;
  winner = 0;
  p1 = &player1;
  p2 = &player2;
  end = false;
  int reval = update(window);
}

Conquer::~Conquer()
{
  std::cout << "Deconstructor for Gameplay" << std::endl;
}

void Conquer::draw(sf::RenderWindow &window)
{
  window.draw(bk);
  drawButtons(window);
 
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
    setScreen();

    //Clearing and drawing
    window.clear();
    draw(window);
    window.display();

    //Return to gmaeplay
    if (end == true)
      return 0 ;
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
  if (!texture[6].loadFromFile("images/b_back.png", sf::IntRect(0, 0, 180, 60)))
    imageFail_important("images/b_back.png");


  a.setTexture(texture[0]);
  b.setTexture(texture[2]);
  c.setTexture(texture[1]);
  attack.setTexture(texture[3]);
  retreat.setTexture(texture[4]);
  label.setTexture(texture[5]);
  back.setTexture(texture[6]);

 
}

//TODO
void Conquer::loadStory()
{
  //Choose a story
  //Load story
  
}

void Conquer::mouseHoverEvent(sf::Event event)
{
  a.checkHover(event.mouseMove.x, event.mouseMove.y);
  b.checkHover(event.mouseMove.x, event.mouseMove.y);
  c.checkHover(event.mouseMove.x, event.mouseMove.y);
  attack.checkHover(event.mouseMove.x, event.mouseMove.y);
  retreat.checkHover(event.mouseMove.x, event.mouseMove.y);
  back.checkHover(event.mouseMove.x, event.mouseMove.y);
}

//TODO need more button actions like retreat going back to gameplay and optiosn
void Conquer::clickEvents()
{

	if (a.mouseClicked()){
		if ((RunningData::getInstance()->SelectedEra == 1) && Questions::getInstance()->AnswersWWII_Select[q] == (Questions::getInstance()->A)){
			part = 2;
		}
		else if ((RunningData::getInstance()->SelectedEra == 2) && Questions::getInstance()->AnswersRoman_Select[q] == (Questions::getInstance()->A)){
			part = 2;
		}
		else{
			//Incorrect Answer
			part = 3;
		}
	}
	else if (b.mouseClicked()){
		if ((RunningData::getInstance()->SelectedEra == 1) && Questions::getInstance()->AnswersWWII_Select[q] == (Questions::getInstance()->B)){
			part = 2;
		}
		else if ((RunningData::getInstance()->SelectedEra == 2) && Questions::getInstance()->AnswersRoman_Select[q] == (Questions::getInstance()->B)){
			part = 2;
		}
		else{
			//Incorrect Answer
			part = 3;
		}
	}
	else if (c.mouseClicked()){
		if ((RunningData::getInstance()->SelectedEra == 1) && Questions::getInstance()->AnswersWWII_Select[q] == (Questions::getInstance()->C)){
			part = 2;
		}
		else if ((RunningData::getInstance()->SelectedEra == 2) && Questions::getInstance()->AnswersRoman_Select[q] == (Questions::getInstance()->C)){
			part = 2;
		}
		else{
			//Incorrect Answer
			part = 3;
		}
	}
	else{
	
	}
  if (back.mouseClicked())
    end = true;
  if (attack.mouseClicked())
    battle();
  if (retreat.mouseClicked())
	  end = true;

}


//Setting positions of buttons and images based on what part
void Conquer::setScreen()
{
  if (part == 1)
  {
    a.setPosition(sf::Vector2f( (x / 6) * 1, y-75));
    b.setPosition(sf::Vector2f( (x / 6) * 3, y - 75));
    c.setPosition(sf::Vector2f( (x / 6) * 5, y - 75));
    story.setPosition(sf::Vector2f(10 ,50));
    question.setPosition(sf::Vector2f(10,y-200));
    //TODO
    loadStory();

    //Test delete below
		if (RunningData::getInstance()->SelectedEra == 1){
			story.setString(Questions::getInstance()->WWII[q] );
			question.setString(Questions::getInstance()->AnswersWWII[q]);
		}
		if (RunningData::getInstance()->SelectedEra == 2){
			story.setString(Questions::getInstance()->Roman[q]);
			question.setString(Questions::getInstance()->AnswersRoman[q]);
		}
		//

  }
  else if (part == 2 )
  {
    str_stats = getStats();
    stats.setString(str_stats);
    label.setPosition(sf::Vector2f((x/2)-200, (y/2)+100));
    attack.setPosition(sf::Vector2f(100, y-150));
    retreat.setPosition(sf::Vector2f(x-300, y - 150));
    stats.setPosition(sf::Vector2f(10, 20));
  }
  else if (part == 3){
	  stats.setString("Wrong Answer, You loose 25 gold");
	  back.setPosition(sf::Vector2f(100, y - 150));
	  wrong();
  }
  else
  {
	  back.setPosition(sf::Vector2f(100, y - 150));
	  if (winner == 1){
		  stats.setString("You Won");
	  }
	  else{
		  stats.setString("You Lose");
	  }
  }
}


//Drawing buttons
void Conquer::drawButtons(sf::RenderWindow &window)
{
  if (part == 1)
  {
    window.draw(a);
    window.draw(b);
    window.draw(c);
    window.draw(story);
    window.draw(question);
  }
  else if (part == 2)
  {
    window.draw(attack);
    window.draw(retreat);
    window.draw(label);
    window.draw(stats);
  }
  else if (part == 3)
  {
	  window.draw(stats);
	  window.draw(back);

  }
  else
  {
    window.draw(stats);
    window.draw(back);
  }
  
}

//Returning stats
string Conquer::getStats()
{
  if (numCorrect == 1)
  {
    return "Enemy Population: " + std::to_string((*p2).getPopluation()) + " Infantry:" + std::to_string((*p2).getInfantryUnits()) +
      " Cavalry:" + std::to_string((*p2).getCavalryUnits());
  }
  else if (numCorrect == 2)
  {
    return "Enemy Population: " + std::to_string((*p2).getPopluation()) + " Infantry:" + std::to_string((*p2).getInfantryUnits()) +
      " Cavalry:" + std::to_string((*p2).getCavalryUnits()) +
      " Siege:" + std::to_string((*p2).getSiegeUnits());
  }
  else
  {
    return "Enemy Population: " + std::to_string((*p2).getPopluation()) + " Infantry:" + std::to_string((*p2).getInfantryUnits());
  }


}


void Conquer::battle()
{
  part = -1;
  RunningData::getInstance()->displayAll();
  //Checks who has bigger army
  if ((*p1).getMilitaryUnits() >= (*p2).getMilitaryUnits())
  {
    winner = 1; //Player wins
	if (RunningData::getInstance()->SelectedColor == 1){
		std::cout << "__--++ G: "<<q;
		RunningData::getInstance()->mapFile[q] = 'g';
	}
	if (RunningData::getInstance()->SelectedColor == 2)
	{
		RunningData::getInstance()->mapFile[q] = 'r';
		std::cout << "__--++ R: "<<q;
	}

  }
  else
  {
    winner = 2; //Ai wins
	if (RunningData::getInstance()->SelectedColor == 1){
		RunningData::getInstance()->mapFile[q] = 'r';
		std::cout << "__--++ R: "<< q;
	}
	if (RunningData::getInstance()->SelectedColor == 2)
	{
		RunningData::getInstance()->mapFile[q] = 'g';
		std::cout << "__--++ G: " << q;
	}
  }

  //Reward winner punish loser
  if (winner == 1)
  {
    (*p1).addGold(500);
    (*p1).addLand(2);
    (*p1).addPopulation(35);
    (*p1).removeCavalryUnit(5);
    (*p1).removeInfantryUnit(10);
    (*p1).removeSiegeUnit(3);

    (*p2).removeGold(500);
    (*p2).removeLand(2);
    (*p2).removePopulation(35);
    (*p2).removeCavalryUnit(10);
    (*p2).removeInfantryUnit(20);
    (*p2).removeSiegeUnit(6);
  }
  else
  {
    (*p2).addGold(500);
    (*p2).addLand(2);
    (*p2).addPopulation(35);
    (*p2).removeCavalryUnit(5);
    (*p2).removeInfantryUnit(10);
    (*p2).removeSiegeUnit(3);

    (*p1).removeGold(500);
    (*p1).removeLand(2);
    (*p1).removePopulation(35);
    (*p1).removeCavalryUnit(10);
    (*p1).removeInfantryUnit(20);
    (*p1).removeSiegeUnit(6);
  }

}

void Conquer::wrong(){
	(*p1).removeGold(25);//A slap on the wrist.

	if (RunningData::getInstance()->SelectedColor == 1){
		RunningData::getInstance()->mapFile[q] = 'r';
		std::cout << "__--++ R: " << q;
	}
	if (RunningData::getInstance()->SelectedColor == 2)
	{
		RunningData::getInstance()->mapFile[q] = 'g';
		std::cout << "__--++ G: " << q;
	}
}
