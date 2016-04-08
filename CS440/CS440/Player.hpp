#pragma once
#ifndef Player_H
#define Player_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using std::string;

class Player
{
protected:
  int score;          //Score
  int gold;           //Currency
  int military;       //Total military untis
  int siegeUnit;      //Num seige unit
  int cavalryUnit;    //Num cavalry
  int infantryUnit;   //Num infantry
  int population;     //Total population - excluding military
  int land;           //Land
  int conqueorCount;  //How many empires desotryed
  int player_color;   //Color of player 0-Red, 1-Green
  bool lose;
public:
	void reInit(int score, int gold, int military, int siegeUnit, int cavalryUnit, int infantryUnit, int population, int land, int conqueorCount, int player_color); //for load game..

  int max_population; //Max people allowed
  int max_military;   //Max military allowed

  //Cost to build resources
  const int siegeCost = 125;
  const int infantryCost =20 ;
  const int populationCost = 20;
  const int cavalryCost = 50;

  Player();
  ~Player();
  //Gold function
  int getGold(){return gold;};  //get golf
  void addGold(int amt);        //add gold by amt
  void addGold(){ gold++; };    //add 1 gold
  bool removeGold(int amt);     //remove gold amt
  void initUnits(int value);    //Give number then initialize

  //Population Function
  int getPopluation(){ return population; };    //get population
  bool addPopulation();                         //add 1 Population
  bool addPopulation(int amt);                  //add amt to population
  bool removePopulation(int amt);               //remove amt from population

  //Getting military units
  int getSiegeUnits(){ return siegeUnit; };
  int getCavalryUnits(){ return cavalryUnit; };
  int getInfantryUnits(){ return infantryUnit; };
  int getMilitaryUnits(){ return (siegeUnit + cavalryUnit + infantryUnit); };

  //Setting military units
  bool addCavalryUnits();
  bool addInfantryUnits();
  bool addSiegeUnits();
  
  //Remove military units
  void removeCavalryUnit(int amt);
  void removeInfantryUnit(int amt);
  void removeSiegeUnit(int amt);

  //Land
  void addLand(int amt);
  int getLand(){ return land; };
  void removeLand(int amt);
  
  //Getting user color
  int getColor(){ return player_color; };

  //Score
  void updateScore();
  int getScore(){ return score; };


};
#endif