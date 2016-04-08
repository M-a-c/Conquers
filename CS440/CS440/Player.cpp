#include "Player.hpp"


Player::Player()
{
  gold = 1000;
  population = 20;
  land = 100;
  conqueorCount = 0;
  addLand(0);
  lose = false;
  //Todo//
  player_color = 0;
  initUnits(1);
  //
  military = siegeUnit+cavalryUnit+infantryUnit;
}

Player::~Player()
{
  std::cout << "Deconstructor for Player" << std::endl;
}

//Init units
void Player::initUnits(int num)
{
  switch (num)
  {
  case 1: //25
    siegeUnit = 6;
    cavalryUnit = 12;
    infantryUnit = 25;
    break;
   case 2: //50
    siegeUnit = 12;
    cavalryUnit = 25;
    infantryUnit = 50;
    break;
  case 3: //100
    siegeUnit = 25;
    cavalryUnit = 50;
    infantryUnit = 100;
    break;
  }
}


//Update score
void Player::updateScore()
{
  //score = gold + (10 * (population)+25) * (seigeUnit + cavalryUnit + infantryUnit) + (conqueorCount);
  score =  (siegeUnit * 9) + (cavalryUnit * 7) + (infantryCost*5) + (12* conqueorCount) + (5*population);
}


//add gold amt
void Player::addGold(int amt)
{
  gold = gold + amt;
}


//remove gold by amt
bool Player::removeGold(int amt)
{ 
  if ((gold - amt) < 0){
    return false;
  }

  gold = gold - amt;
  return true;
}


//add 1 to population
bool Player::addPopulation()
{
  if ((population + 1) > max_population)
    return false;
  
  population++;
  return true;
    
}


//add amt to population
bool Player::addPopulation(int amt)
{
  //No exceeding max
  if ((population + amt) > max_population)
    return false;

  //Add population
  population = population+amt;
  return true;
}


//rm amt from population
bool Player::removePopulation(int amt)
{
  //Can remove check
  if ((population - amt) < 0)
    return false;

  //Remove
  population = population - amt;
  return true;
}


//Add land
void Player::addLand(int amt)
{
  land = land + amt;
  //Reset populstion
  max_population = (land * 10)/2;
  max_military = (land * 10) / 2;
}


//remove land
void Player::removeLand(int amt)
{
  land = land - amt;
  
  //Check if lost whole territory
  if (land <= 0)
    lose = true;
}

//Add cavalry untis
bool Player::addCavalryUnits()
{
  //Check people limit
  if ((military + 1) > max_military)
    return false;

  //Add unit
  cavalryUnit++;
  military++;
  return true;

}


//Add infantry unit
bool Player::addInfantryUnits()
{
  //Check people limit
  if ((military + 1) > max_military)
    return false;

  //Add unit
  infantryUnit++;
  military++;
  return true;
}


//Adding siege Unit
bool Player::addSiegeUnits()
{
  //Check  people limit
  if ((military + 1) > max_military)
    return false;

  //Add unit
  siegeUnit++;
  military++;
  return true;
}


//Removing Siege unit
void Player::removeSiegeUnit(int amt)
{
  siegeUnit = siegeUnit - amt;
  military = military - amt;

  if (siegeUnit < 0)
  {
    int rem = abs(siegeUnit);
    siegeUnit = 0;
    military = military + rem;
  }
   
}


//Remove infantry unit
void Player::removeInfantryUnit(int amt)
{
  infantryUnit = infantryUnit - amt;
  military = military - amt;

  if (infantryUnit < 0)
  {
    int rem = abs(infantryUnit);
    infantryUnit = 0;
    military = military + rem;
  }
}


//Remove cavalry unit
void Player::removeCavalryUnit(int amt)
{
  cavalryUnit = siegeUnit - amt;
  military = military - amt;

  if (cavalryUnit < 0)
  {
    int rem = abs(cavalryUnit);
    cavalryUnit = 0;
    military = military + rem;
  }
}

void Player::reInit(int score, int gold, int military, int siegeUnit, int cavalryUnit, int infantryUnit, int population, int land, int conqueorCount, int player_color) {

	this->score = score;
	this->gold = gold;
	this->military = military;
	this->siegeUnit = siegeUnit;
	this->cavalryUnit = cavalryUnit;
	this->infantryUnit = infantryUnit;
	this->population = population;
	this->land = land;
	this->conqueorCount = conqueorCount;
	this->player_color = player_color;
}