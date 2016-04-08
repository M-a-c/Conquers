//Singelton design pattern.
//Sourced from.
//http://stackoverflow.com/questions/1008019/c-singleton-design-pattern

#pragma once 
#include <list>
#include "StringInput.hpp"
#include "string"

class Questions {
public:
	static Questions* getInstance()
	{
		static Questions instance; // Guaranteed to be destroyed.
		// Instantiated on first use.
		return &instance;
	}
private:
	Questions() {};                  // Constructor? (the {} brackets) are needed here.
	int Counter = 0;

public:
	void gameInit();
	Questions(Questions const&) = delete;
	void operator=(Questions const&) = delete;
	int getNextQuestion();
	void setQuestion(int c);
	
	enum Answers {A,B,C};
	int Era;//WW2 or Roman.
	

	string WWII[4];
	string AnswersWWII[4];
	Answers AnswersWWII_Select[4];


	//The Roman Republic - Gallic Wars and The First Triumvirate - (59 BC - 30 BC)
	string Roman[4];
	string AnswersRoman[4];
	int AnswersRoman_Select[4];



	// if(RunningData.)

	// Note: Scott Meyers mentions in his Effective Modern
	//       C++ book, that deleted functions should generally
	//       be public as it results in better error messages
	//       due to the compilers behavior to check accessibility
	//       before deleted status
};