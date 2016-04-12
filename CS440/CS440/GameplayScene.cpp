#include "GameplayScene.hpp"

Gameplay::Gameplay(sf::RenderWindow &window,int &re_val)
{
  //Setting game variables
  name = "Gameplay";                          
  userTurn = true;

  ///NEW CHANGES///
  canConquer = true;
  
  TempTime = 0;
 
  //New game
  //if (!loadGame)                             
  //{
    initTimers(0, 0);                          //Initialze time TODO 
    getImage((float)window.getSize().x,       //Load images
      (float)window.getSize().y);

	if (RunningData::getInstance()->maxMilitary == 0){
		std::cout << "*******************";
	}
	else{
		loadGame();
	}

	if (RunningData::getInstance()->SelectedEra == 1){
		if (!BgTextuer.loadFromFile("images/WWII/" + RunningData::getInstance()->mapFile + ".jpg", sf::IntRect(0, 0, 1366, 768)))
			imageFail_important("images/WWII/" + RunningData::getInstance()->mapFile + ".jpg");
	}
	if (RunningData::getInstance()->SelectedEra == 2){
		if (!BgTextuer.loadFromFile("images/Roman/" + RunningData::getInstance()->mapFile + ".jpg", sf::IntRect(0, 0, 1366, 768)))
			imageFail_important("images/Roman/" + RunningData::getInstance()->mapFile + ".jpg");
	}

	BgSprite.setTexture(BgTextuer);
	BgSprite.setScale(0.8f, 0.8f);
	BgSprite.setPosition(200, 0);

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
  window.draw(BgSprite);
  window.draw(score);
  window.draw(time);
  window.draw(totalTime);
  //Drawing non attack buttons

  for (int i = 0; i < 7; i++)
  {
    window.draw(icons[i]);
    window.draw(iconVal[i]);
  }
  drawButtons(window);

  if (userTurn == false)
    window.draw(icons[7]);
  

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
			if (clickEvents(window)){
				return MainMenuScene;
			}
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
    //Score lable
    score.setFont(font);
    score.setColor(sf::Color::White);
    score.setString("Score:");
    score.setPosition(5, 10);

    //Time label
    time.setFont(font);
    time.setColor(sf::Color::White);
    time.setString("Time:");
    time.setPosition(5, 45);

    //Time label
    totalTime.setFont(font);
    totalTime.setColor(sf::Color::White);
    totalTime.setString("Game Time:");
    totalTime.setPosition(5, 80);

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
  if (!texture[5].loadFromFile("images/seige_unit.png", sf::IntRect(0, 0, 48, 48)))
    imageFail_important("images/seige_unit.png");
  if (!texture[4].loadFromFile("images/cav_unit.png", sf::IntRect(0, 0, 48, 48)))
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
  if (!texture[14].loadFromFile("images/player2.png", sf::IntRect(0, 0, 180, 60)))
    imageFail_important("images/player2.png");

  icons[0].setTexture(texture[0]);
  icons[1].setTexture(texture[1]);
  icons[2].setTexture(texture[2]);
  icons[3].setTexture(texture[3]);
  icons[4].setTexture(texture[4]);
  icons[5].setTexture(texture[5]);
  icons[6].setTexture(texture[6]);
  icons[7].setTexture(texture[14]);

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
  icons[7].setPosition(sf::Vector2f(width/2-90,height/2-30));

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
  endTurn_button.checkHover(event.mouseMove.x, event.mouseMove.y);
  menu.checkHover(event.mouseMove.x, event.mouseMove.y);
  ///NEW CHANGES///
  if (canConquer)
    attack.checkHover(event.mouseMove.x, event.mouseMove.y);
}


//Checking for click events
int Gameplay::clickEvents(sf::RenderWindow &window)
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

  ///NEW CHANGES///
  else if (attack.mouseClicked() && canConquer)
  {
	  saveGame();
	  Conquer conquer(window,player1,player2);
	 
	  if (RunningData::getInstance()->SelectedEra == 1){
		  if (!BgTextuer.loadFromFile("images/WWII/" + RunningData::getInstance()->mapFile + ".jpg", sf::IntRect(0, 0, 1366, 768)))
			  imageFail_important("images/WWII/" + RunningData::getInstance()->mapFile + ".jpg");
	  }
	  if (RunningData::getInstance()->SelectedEra == 2){
		  if (!BgTextuer.loadFromFile("images/Roman/" + RunningData::getInstance()->mapFile + ".jpg", sf::IntRect(0, 0, 1366, 768)))
			  imageFail_important("images/Roman/" + RunningData::getInstance()->mapFile + ".jpg");
	  }
  
	  BgSprite.setTexture(BgTextuer);

    ///NEW CHANGES///
    canConquer = false;

   //Conquer mode 
  }

  //End turn button clicked
  else if (endTurn_button.mouseClicked())
  {
    endTurn();
    ///NEW CHANGES///
    canConquer = true;
  }

  //Save and exit clicked
  else if (menu.mouseClicked())
  {
	  saveGame();
	  return 1;
    //TODO
    //Save and quit need to be returned
  }


  return 0;

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
  time.setString("Round:" + to_string((int)roundTime.getElapsedTime().asSeconds()) );
  totalTime.setString("Game: " + to_string((int)(gameTimer.getElapsedTime().asSeconds() + TempTime)));
}
//Drawing buttons referenced by draw function
void Gameplay::drawButtons(sf::RenderWindow &window)
{

  window.draw(increasePopulation);
  window.draw(increaseInfantry);
  window.draw(increaseCavalry);
  window.draw(increaseSeige);
  window.draw(endTurn_button);
  window.draw(menu);
  ///NEW CHANGES///
  if (canConquer)
    window.draw(attack);
}

//Ending user turn 
void Gameplay::endTurn()
{
	RunningData::getInstance()->save();//Save.
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


void Gameplay::saveGame(){

	RunningData * r = RunningData::getInstance();


		r->currentGameTime = gameTimer.getElapsedTime().asSeconds() + TempTime;

		//int questionIndex = 0//FIX
			
		r->score = player1.getScore();
		r->gold = player1.getGold();
		r->population = player1.getPopluation();
		r->land = player1.getLand();
		r->conquerCount = player1.getConqueorCount();
		r->color = player1.getColor();
		r->siegeUnit = player1.getSiegeUnits();
		r->cavalryUnit = player1.getCavalryUnits();
		r->infantryUnit = player1.getInfantryUnits();
		r->maxMilitary = player1.max_military;
		r->maxPopulaiton = player1.max_population;
		r->military = player1.getMilitaryUnits();//combo of units

			r->turnCounter = userTurn;


		r->Ai_score = player2.getScore();
		r->Ai_gold = player2.getGold();
		r->Ai_population = player2.getPopluation();
		r->Ai_land = player2.getLand();
		r->Ai_conquerCount = player2.getConqueorCount();
		r->Ai_color = player2.getColor();
		r->Ai_siegeUnit = player2.getSiegeUnits();
		r->Ai_cavalryUnit = player2.getCavalryUnits();
		r->Ai_infantryUnit = player2.getInfantryUnits();
		r->Ai_maxMilitary = player2.max_military;
		r->Ai_maxPopulaiton = player2.max_population;
		r->Ai_military = player2.getMilitaryUnits();//combo of units

		r->save();
		r->displayAll();
}


void Gameplay::loadGame(){



	RunningData * r = RunningData::getInstance();

	Questions::getInstance()->setQuestion(0);
	Questions::getInstance()->Era = r->SelectedEra;
	TempTime = r->currentGameTime;

	player1.reInit(r->score,r->gold,r->military,r->siegeUnit,r->cavalryUnit,r->infantryUnit,r->population,r->land,r->conquerCount,r->color);
	std::cout << "\n******************************************************" << r->Ai_color<<"********************************\n";
	player2.reInit(r->Ai_score, r->Ai_gold, r->Ai_military, r->Ai_siegeUnit, r->Ai_cavalryUnit, r->Ai_infantryUnit, r->Ai_population, r->Ai_land, r->Ai_conquerCount, r->Ai_color);
  
  ///NEW CHANGES///
  canConquer = true;

	r->displayAll();
}


