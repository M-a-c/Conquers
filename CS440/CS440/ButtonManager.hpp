//Singelton design pattern.
//Sourced from.
//http://stackoverflow.com/questions/1008019/c-singleton-design-pattern

#pragma once 
#include <list>
#include "Button.hpp"

class ButtonManager {
public:
	static ButtonManager& getInstance()
	{
		static ButtonManager instance; // Guaranteed to be destroyed.
		// Instantiated on first use.
		return instance;
	}
private:
	ButtonManager();                   // Constructor? (the {} brackets) are needed here.
	~ButtonManager();
	
public:
	ButtonManager(ButtonManager const&) = delete;
	void operator=(ButtonManager const&) = delete;
	std::list < Button > buttons;
	int update();//Return this value, it will switch the scene
	// if(ButtonManager.)

	// Note: Scott Meyers mentions in his Effective Modern
	//       C++ book, that deleted functions should generally
	//       be public as it results in better error messages
	//       due to the compilers behavior to check accessibility
	//       before deleted status
};