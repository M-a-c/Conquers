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
#include "Questions.hpp"

class Conquer : public Scene
{
private:

public:
  Conquer(sf::RenderWindow &window,Player &player1, Ai &player2);
  ~Conquer();
private:

  //1 - Story //2 - Attack or un //3 - Win or loss
  int q;
  int part;//Which sections  
  int x, y;//Width,height
  int numCorrect;//Questions answered correctly
  int winner;
  Player* p1;
  Ai* p2;
  bool end;       //Should it return to gameplay

  sf::Font font;  //Font


  //Buttons and labels
  sf::Texture texture[7];
  Button a;
  Button b;
  Button c;
  Button retreat;
  Button attack;
  Button back;
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
  void drawButtons(sf::RenderWindow &window);   //Drawing buttons

  //Events
  void mouseHoverEvent(sf::Event);              //Mouse is hover over buttons
  void clickEvents();                           //Events based on click
  
  //Load
  void loadStory();                             //Load story from file
  void setScreen();                             //Set up screen to draw

  //Gameplay
  string getStats();                            //returns stats based on questions answered correctly
  void battle();                                //Battle logic
  void wrong();									//When the user gets something wrong.


};