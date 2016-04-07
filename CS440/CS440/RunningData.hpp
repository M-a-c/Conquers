//Singelton design pattern.
//Sourced from.
//http://stackoverflow.com/questions/1008019/c-singleton-design-pattern

#pragma once 
#include <list>
#include "StringInput.hpp"
#include "string"


class RunningData {
public:
	static RunningData* getInstance()
	{
		static RunningData instance; // Guaranteed to be destroyed.
		// Instantiated on first use.
		return &instance;
	}
private:
	RunningData() {};                  // Constructor? (the {} brackets) are needed here.

public:
	RunningData(RunningData const&) = delete;
	void operator=(RunningData const&) = delete;
	void save();
	void reset();

	float SelectedRoundTime;
	float SelectedGameTime;
	int SelectedColor;
	int SelectedEra;
	int SelectedUnitNumber;

	float currentGameTime;

	int questionIndex;

	int score;
	int gold;
	int population;
	int land;
	int conquerCount;
	int color;
	int siegeUnit;
	int cavalryUnit;
	int infantryUnit;
	int maxMilitary;
	int maxPopulaiton;
	int military;//combo of units
	bool turnCoutner;
	string PlayerName;
	string PlayerPassword;

	int Ai_score;
	int Ai_gold;
	int Ai_population;
	int Ai_land;
	int Ai_conquerCount;
	int Ai_color;
	int Ai_siegeUnit;
	int Ai_cavalryUnit;
	int Ai_infantryUnit;
	int Ai_maxMilitary;
	int Ai_maxPopulaiton;
	int Ai_military;//combo of units


	// if(RunningData.)

	// Note: Scott Meyers mentions in his Effective Modern
	//       C++ book, that deleted functions should generally
	//       be public as it results in better error messages
	//       due to the compilers behavior to check accessibility
	//       before deleted status
};