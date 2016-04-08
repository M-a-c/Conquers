#include "RunningData.hpp"


void RunningData::save(){
	//Call datamanger from here.
	DataManager d;
	d.saveRunningData(PlayerName);
}

void RunningData::reset(){


	float SelectedRoundTime = 0.0f;
	float SelectedGameTime = 0.0f;
	int SelectedColor = 0;
	int SelectedEra = 0;
	int SelectedUnitNumber = 0;

	float currentGameTime = 0.0f;

	int questionIndex = 0;

	int score = 0;
	int gold = 0;
	int population = 0;
	int land = 0;
	int conquerCount = 0;
	int color = 0;
	int siegeUnit = 0;
	int cavalryUnit = 0;
	int infantryUnit = 0;
	int maxMilitary = 0;
	int maxPopulaiton = 0;
	int military = 0;//combo of units
	bool turnCounter = 0;
	string PlayerName = "";
	string PlayerPassword = "";

	int Ai_score = 0;
	int Ai_gold = 0;
	int Ai_population = 0;
	int Ai_land = 0;
	int Ai_conquerCount = 0;
	int Ai_color = 0;
	int Ai_siegeUnit = 0;
	int Ai_cavalryUnit = 0;
	int Ai_infantryUnit = 0;
	int Ai_maxMilitary = 0;
	int Ai_maxPopulaiton = 0;
	int Ai_military = 0;//combo of units

}

void RunningData::displayAll(){

	std::cout << "float SelectedRoundTime: " << SelectedRoundTime << std::endl;
	std::cout << "float SelectedGameTime: " << SelectedGameTime << std::endl;
	std::cout << "int SelectedColor: " << SelectedColor << std::endl;
	std::cout << "int SelectedEra: " << SelectedEra << std::endl;
	std::cout << "int SelectedUnitNumber: " << SelectedUnitNumber << std::endl;
	std::cout << "float currentGameTime: " << currentGameTime << std::endl;
	std::cout << "int questionIndex: " << questionIndex << std::endl;
	std::cout << "int score: " << score << std::endl;
	std::cout << "int gold: " << gold << std::endl;
	std::cout << "int population: " << population << std::endl;
	std::cout << "int land: " << land << std::endl;
	std::cout << "int conquerCount: " << conquerCount << std::endl;
	std::cout << "int color: " << color << std::endl;
	std::cout << "int siegeUnit: " << siegeUnit << std::endl;
	std::cout << "int cavalryUnit: " << cavalryUnit << std::endl;
	std::cout << "int infantryUnit: " << infantryUnit << std::endl;
	std::cout << "int maxMilitary: " << maxMilitary << std::endl;
	std::cout << "int maxPopulaiton: " << maxPopulaiton << std::endl;
	std::cout << "int military: " << military << std::endl;
	std::cout << "bool turnCoutner: " << turnCounter << std::endl;
	std::cout << "string PlayerName: " << PlayerName << std::endl;
	std::cout << "string PlayerPassword: " << PlayerPassword << std::endl;
	std::cout << "int Ai_score: " << Ai_score << std::endl;
	std::cout << "int Ai_gold: " << Ai_gold << std::endl;
	std::cout << "int Ai_population: " << Ai_population << std::endl;
	std::cout << "int Ai_land: " << Ai_land << std::endl;
	std::cout << "int Ai_conquerCount: " << Ai_conquerCount << std::endl;
	std::cout << "int Ai_color: " << Ai_color << std::endl;
	std::cout << "int Ai_siegeUnit: " << Ai_siegeUnit << std::endl;
	std::cout << "int Ai_cavalryUnit: " << Ai_cavalryUnit << std::endl;
	std::cout << "int Ai_infantryUnit: " << Ai_infantryUnit << std::endl;
	std::cout << "int Ai_maxMilitary: " << Ai_maxMilitary << std::endl;
	std::cout << "int Ai_maxPopulaiton: " << Ai_maxPopulaiton << std::endl;
	std::cout << "int Ai_military: " << Ai_military << std::endl;

}