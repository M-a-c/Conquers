#pragma once 
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Failure.hpp"
#include "Scenes.cpp"
#include "Button.hpp"
#include "Player.hpp"
#include "Ai.hpp"

class Conquer : public Scene
{
private:

public:
  Conquer(sf::RenderWindow &window,Player &player1, Ai &player2);
  ~Conquer();
private:

  int part;       //Story(1) or battle(2)

  sf::Font font;  //Font


  //Buttons and labels
  sf::Texture texture[7];
  Button a;
  Button b;
  Button c;
  Button retreat;
  Button attack;
  sf::Sprite label;

  //Story
  sf::Text story;
  sf::Text question;
  string str_story;
  string str_question;
  int answer;

  //Battle stats
  sf::Text stats;
  string str_stats;

  //Render & Load
  void draw(sf::RenderWindow &window);          //Drawing onto screen
  int update(sf::RenderWindow &window);         //Updating status
  void getImage(float width, float height);     //Getting images
  void drawButtons(sf::RenderWindow &window,int index);   //Drawing buttons

  //Events
  void mouseHoverEvent(sf::Event);              //Mouse is hover over buttons
  void clickEvents();                           //Events based on click
  
  //Load
  void loadStory();                             //Load story from file

  //Gameplay
  void battle();                                //Battle
  void rewardWinner();                          //Reward winner of battle


};