#include "RunningData.hpp"


void RunningData::save(){
	//Call datamanger from here.
	DataManager d;
	d.saveRunningData(PlayerName);
}

void RunningData::reset(){

	SelectedRoundTime = 0.0f;
	SelectedGameTime = 0.0f;
	SelectedColor = 0;
	SelectedEra = 0;
	SelectedUnitNumber = 0;

	currentGameTime = 0.0f;

	questionIndex = 0;

	score = 0;
	gold = 0;
	population = 0;
	land = 0;
	conquerCount = 0;
	color = 0;
	siegeUnit = 0;
	cavalryUnit = 0;
	infantryUnit = 0;
	maxMilitary = 0;
	maxPopulaiton = 0;
	military = 0;//combo of units
	turnCounter = 0;
	PlayerName = "";
	PlayerPassword = "";

	Ai_score = 0;
	Ai_gold = 0;
	Ai_population = 0;
	Ai_land = 0;
	Ai_conquerCount = 0;
	Ai_color = 0;
	Ai_siegeUnit = 0;
	Ai_cavalryUnit = 0;
	Ai_infantryUnit = 0;
	Ai_maxMilitary = 0;
	Ai_maxPopulaiton = 0;
	Ai_military = 0;//combo of units

	mapFile = "wwww";

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
	std::cout << "string mapFile: " << mapFile << std::endl;

}