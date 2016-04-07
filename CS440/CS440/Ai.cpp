#include "Ai.hpp"


Ai::Ai()
{
  gold = 1000;
  population = 20;
  land = 100;
  conqueorCount = 0;
  addLand(0);
  //Edit this based on incoming
  player_color = 1;
  initUnits(1);
  //
  military = siegeUnit + cavalryUnit + infantryUnit;
}

Ai::~Ai()
{
  std::cout << "This is a deconstructor for AI" << std::endl;
}

void Ai::runAI()
{
  for (int i = 0; i < 10; i++)
  {
    if (removeGold(populationCost) == true)
      addPopulation();

    std::cout << "Ai worker:" << population << "/" << max_population << " $" << gold << std::endl;
  }
  for (int i = 0; i < 20; i++)
  {
    if (removeGold(infantryCost) == true)
      addInfantryUnits();

    std::cout << "Ai infantry" << infantryUnit << "/" << max_military << " $" << gold << std::endl;
  }
  for (int i = 0; i < 10; i++)
  {
    if (removeGold(cavalryCost) == true)
      addCavalryUnits();

    std::cout << "Ai Cavalry" << cavalryUnit << "/" << max_military << " $" << gold << std::endl;
  }
  for (int i = 0; i < 5; i++)
  {
    if (removeGold(siegeCost) == true)
      addSiegeUnits();

    std::cout << "Ai Seige" << siegeUnit << "/" << max_military << " $" << gold << std::endl;
  }

}

void Ai::winWar(int gold_amt, int land_amt, int worker)
{
  addGold(gold_amt);
  addLand(land_amt);
  addPopulation(worker);
}