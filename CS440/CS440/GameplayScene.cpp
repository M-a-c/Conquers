#include "GameplayScene.hpp"

Gameplay::Gameplay(sf::RenderWindow &window,int &re_val)
{
  //Setting game variables
  name = "Gameplay";                          
  userTurn = true;
  
  //New game
  //if (!loadGame)                             
  //{
    initTimers(0,0);                          //Initialze time TODO 
    getImage((float)window.getSize().x,       //Load images
      (float)window.getSize().y);
    re_val = update(window);                  //update and next scene
    return;
  //}

  //TODO
  //Load game from file
 // else                                        
  //{
    //Login into game 
  //}

}

Gameplay::~Gameplay()
{
  std::cout << "Deconstructor for Gameplay" << std::endl;
}

void Gameplay::draw(sf::RenderWindow &window)
{
  
  window.draw(score);
  window.draw(time);
  //Drawing non attack buttons

  for (int i = 0; i < 7; i++)
  {
    window.draw(icons[i]);
    window.draw(iconVal[i]);
  }
  drawButtons(window);
  

}

int Gameplay::update(sf::RenderWindow &window)
{
  while (window.isOpen())
  {
    sf::Event event;

    //Look for event
    while (window.pollEvent(event)&& userTurn){

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

    clockEvents();    //Clock based things

    //Score updating
    player1.updateScore();
    player2.updateScore();

    //Clearing and drawing
    updateStats();
    window.clear();
    draw(window);
    window.display();

  }
  return 0;
}

void Gameplay::getImage(float width, float height)
{

  //Loading Font
  if (!font.loadFromFile("arial.ttf"))
  {
    fontFail("arial.tff");
  }
  else
  {
    //username lable
    score.setFont(font);
    score.setColor(sf::Color::White);
    score.setString("Score:");
    score.setPosition(10, 10);

    //password label
    time.setFont(font);
    time.setColor(sf::Color::White);
    time.setString("Time:");
    time.setPosition(10, 45);

    for (int i = 0; i < 7; i++)
    {
      iconVal[i].setFont(font);
      iconVal[i].setColor(sf::Color::White);
      iconVal[i].setPosition(sf::Vector2f(68, (height / 10) * (i+2) ));
    }

  }

  if (!texture[0].loadFromFile("images/gold.png", sf::IntRect(0, 0, 48, 48)))
    imageFail_important("images/gold.png");
  if (!texture[1].loadFromFile("images/land.png", sf::IntRect(0, 0, 48, 48)))
    imageFail_important("images/land.png");
  if (!texture[2].loadFromFile("images/population.png", sf::IntRect(0, 0, 48, 48)))
    imageFail_important("images/population.png");
  if (!texture[3].loadFromFile("images/infan_unit.png", sf::IntRect(0, 0, 48, 48)))
    imageFail_important("images/infan_unit.png");
  if (!texture[4].loadFromFile("images/seige_unit.png", sf::IntRect(0, 0, 48, 48)))
    imageFail_important("images/seige_unit.png");
  if (!texture[5].loadFromFile("images/cav_unit.png", sf::IntRect(0, 0, 48, 48)))
    imageFail_important("images/cav_unit.png");
  if (!texture[6].loadFromFile("images/mili_unit.png", sf::IntRect(0, 0, 48, 48)))
    imageFail_important("images/mili_unit.png");

  if (!texture[7].loadFromFile("images/add_worker.png", sf::IntRect(0, 0, 153, 40)))
    imageFail_important("images/add_worker.png");
  if (!texture[8].loadFromFile("images/add_infantry.png", sf::IntRect(0, 0, 158, 40)))
    imageFail_important("images/add_infantry.png");
  if (!texture[9].loadFromFile("images/add_cavalry.png", sf::IntRect(0, 0, 154, 40)))
    imageFail_important("images/add_cavalry.png");
  if (!texture[10].loadFromFile("images/add_seige.png", sf::IntRect(0, 0, 125, 40)))
    imageFail_important("images/add_seige.png");
  if (!texture[11].loadFromFile("images/conquer.png", sf::IntRect(0, 0, 109, 40)))
    imageFail_important("images/conquer.png");
  if (!texture[12].loadFromFile("images/end_turn.png", sf::IntRect(0, 0, 130, 40)))
    imageFail_important("images/end_turn.png");
  if (!texture[13].loadFromFile("images/save_exit.png", sf::IntRect(0, 0, 130, 40)))
    imageFail_important("images/save_exit.png");

  icons[0].setTexture(texture[0]);
  icons[1].setTexture(texture[1]);
  icons[2].setTexture(texture[2]);
  icons[3].setTexture(texture[3]);
  icons[4].setTexture(texture[4]);
  icons[5].setTexture(texture[5]);
  icons[6].setTexture(texture[6]);

  attack.setTexture(texture[11]);
  endTurn_button.setTexture(texture[12]);
  increasePopulation.setTexture(texture[7]);
  increaseSeige.setTexture(texture[10]);
  increaseCavalry.setTexture(texture[9]);
  increaseInfantry.setTexture(texture[8]);
  menu.setTexture(texture[13]);

  icons[0].setPosition(sf::Vector2f(10, (height / 10)*2 ));
  icons[1].setPosition(sf::Vector2f(10, (height / 10)*3 ));
  icons[2].setPosition(sf::Vector2f(10, (height / 10)*4 ));
  icons[3].setPosition(sf::Vector2f(10, (height / 10)*5 ));
  icons[4].setPosition(sf::Vector2f(10, (height / 10)*6 ));
  icons[5].setPosition(sf::Vector2f(10, (height / 10)*7 ));
  icons[6].setPosition(sf::Vector2f(10, (height / 10)*8 ));

  increasePopulation.setPosition(sf::Vector2f(10, height - 60));
  increaseInfantry.setPosition(sf::Vector2f(183, height - 60));
  increaseCavalry.setPosition(sf::Vector2f(371, height - 60));
  increaseSeige.setPosition(sf::Vector2f(555, height - 60));
  attack.setPosition(sf::Vector2f(710, height - 60));
  endTurn_button.setPosition(sf::Vector2f(860, height - 60));
  menu.setPosition(sf::Vector2f(1020, height - 60));
  
}

//Mouse hover checks
void Gameplay::mouseHoverEvent(sf::Event event)
{
  increasePopulation.checkHover(event.mouseMove.x, event.mouseMove.y);
  increaseInfantry.checkHover(event.mouseMove.x, event.mouseMove.y);
  increaseCavalry.checkHover(event.mouseMove.x, event.mouseMove.y);
  increaseSeige.checkHover(event.mouseMove.x, event.mouseMove.y);
  attack.checkHover(event.mouseMove.x, event.mouseMove.y);
  endTurn_button.checkHover(event.mouseMove.x, event.mouseMove.y);
  menu.checkHover(event.mouseMove.x, event.mouseMove.y);
  
}


//Checking for click events
void Gameplay::clickEvents()
{

  if (increasePopulation.mouseClicked())
  {
    if (player1.removeGold(player1.populationCost) == false)
    {
      //Color change
    }
    else if(player1.addPopulation() == false)
    {
      //change color
    }
  }

  else if (increaseInfantry.mouseClicked())
  {
    if (player1.removeGold(player1.infantryCost) == false)
    {
      //Color change
    }
    else if (player1.addInfantryUnits() == false)
    {
      //change color
    }
  }

  else if (increaseCavalry.mouseClicked())
  {
    if (player1.removeGold(player1.cavalryCost) == false)
    {
      //Color change
    }
    else if (player1.addCavalryUnits() == false)
    {
      //change color
    }
  }

  else if (increaseSeige.mouseClicked())
  {
    if (player1.removeGold(player1.siegeCost) == false)
    {
      //Color change
    }
    else if (player1.addSiegeUnits() == false)
    {
      //change color
    }
  }

  //TODO//
  else if (attack.mouseClicked())
  {
   //Conquer mode 
  }

  //End turn button clicked
  else if (endTurn_button.mouseClicked())
  {
    endTurn();
  }

  //Save and exit clicked
  else if (menu.mouseClicked())
  {
    //TODO
    //Save and quit need to be returned
  }


    

}

//Update status variables
void Gameplay::updateStats()
{
  iconVal[0].setString(to_string(player1.getGold()));
  iconVal[1].setString(to_string(player1.getLand()));
  iconVal[2].setString(to_string( player1.getPopluation() ) + " / " + to_string(player1.max_population));
  iconVal[3].setString(to_string(player1.getInfantryUnits()));
  iconVal[4].setString(to_string(player1.getCavalryUnits()));
  iconVal[5].setString(to_string(player1.getSiegeUnits()));
  iconVal[6].setString(to_string(player1.getMilitaryUnits()) + " / " + to_string(player1.max_military));
  score.setString("Score:"+to_string(player1.getScore()));
  time.setString("Time:" + to_string((int)roundTime.getElapsedTime().asSeconds()) + "/" + to_string((int)gameTimer.getElapsedTime().asSeconds()));
}

//Drawing buttons referenced by draw function
void Gameplay::drawButtons(sf::RenderWindow &window)
{
  window.draw(increasePopulation);
  window.draw(increaseInfantry);
  window.draw(increaseCavalry);
  window.draw(increaseSeige);
  window.draw(attack);
  window.draw(endTurn_button);
  window.draw(menu);
}

//Ending user turn 
void Gameplay::endTurn()
{
  elapsedTime = roundTime.restart();  //restart time
  userTurn = false;                   //Turn off user
}

//TODO - correct timing//
void Gameplay::initTimers(int roundTime_min, int gameTime_min)
{
  //TODO//
  gameMaxTime = sf::seconds(60 * 10);
  roundMaxTime = sf::seconds(60);

  //Init clock stuff
  roundTime.restart();
  gameTimer.restart();
  getMoney = true;
}

//Clock based events
void Gameplay::clockEvents()
{
  
  //Checking if round time max has been reached
  if (roundTime.getElapsedTime() >= roundMaxTime){
    //End user turn
    endTurn();
  }

  //Checking if pay time and can get payed
  if ((int)gameTimer.getElapsedTime().asSeconds() % 10 == 0 && getMoney){
    //Add money to both users
    player1.addGold(player1.getPopluation());
    player2.addGold(player2.getPopluation());
    
    getMoney = false;//Dont add money for a while due to numbers being in float
    prevMoneyTime = gameTimer.getElapsedTime();//get paytime
  }

  //Check if time has passed
  if ((int)prevMoneyTime.asSeconds() < (int)gameTimer.getElapsedTime().asSeconds()){
    getMoney = true;  //Next pay time is set to true
  }

  //Wait for 7 seconds to pass and not user turn
  if (userTurn == false && roundTime.getElapsedTime().asSeconds() > 7)
  {
    player2.runAI();  //Run AI
    userTurn = true;  //user turn true
    elapsedTime = roundTime.restart();  //Restart Timer
  }

}




