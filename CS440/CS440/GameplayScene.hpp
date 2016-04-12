#pragma once 
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Failure.hpp"
#include "Scenes.cpp"
#include "Button.hpp"
#include "Player.hpp"
#include "Ai.hpp"
#include "RunningData.hpp"
#include "ConquerScene.hpp"

using std::string;
using std::to_string;

class Gameplay :public Scene
{
private:

  Player player1;   //User
  Ai player2;       //AI

  bool userTurn;    //Currently user turn
  bool getMoney;    //can recieve money
  bool canConquer;  //User can conquer

  //images
  sf::Texture texture[15];  //Textures    /*0-Gold   1-Land  2-Population  3-infan   4-seige  5-cav  6-military */
  sf::Sprite icons[8];      //Icons
  sf::Text iconVal[7];      //Icon values as text

  sf::Sprite BgSprite;	    //the bakground Map
  sf::Texture BgTextuer;    //The background Map

  Button attack;            //Button to attack
  Button endTurn_button;    //Button to end turn
  Button increasePopulation;//Button to increase population
  Button increaseSeige;     //Button to increase seige units
  Button increaseCavalry;   //Button to increase cavalry unit
  Button increaseInfantry;  //Button to increase infantry unit
  Button menu;              //Button for menu

  //Fonts & Text
  sf::Font font;
  sf::Text score;
  sf::Text time;
  sf::Text totalTime;

  //Time based things
  sf::Clock roundTime;
  sf::Clock gameTimer;
  sf::Time elapsedTime;
  sf::Time roundMaxTime;
  sf::Time gameMaxTime;
  sf::Time prevMoneyTime;

  float TempTime; //where time is put after it is retrived from the load.

public:
  //Constructor and deconstructor
  Gameplay(sf::RenderWindow &window, int &re_val);
  ~Gameplay();
private:
  //Render & Load
  void draw(sf::RenderWindow &window);          //Drawing onto screen
  int update(sf::RenderWindow &window);         //Updating status
  void getImage(float width, float height);     //Getting images

  //Events
  void mouseHoverEvent(sf::Event);              //Mouse is hover over buttons
  int clickEvents(sf::RenderWindow	&window);                           //Events based on click
  void endTurn();                               //End turn functions
  void updateStats();                           //Update stats

  //Draw
  void drawButtons(sf::RenderWindow &window);   //Draw the buttons

  //Time
  void initTimers(int roundTime,int gameTime);  //Init the clock
  void clockEvents();                           //Clock based events

  //Attack
  void clickEventsAttack();                     //Events based on click for attack
  void drawButtonsAttack(
    sf::RenderWindow &window);                  //Drawing attack buttons

  //Save Game
  void saveGame();                              //Save game
  void loadGame();								//Load game
};