//Singelton design pattern.
//Sourced from.
//http://stackoverflow.com/questions/1008019/c-singleton-design-pattern
#pragma once 

#include <list>
#include "ButtonManager.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "StringInput.hpp"
#include <list>
#include "Button.hpp"

class InputManager {
public:
	static InputManager* getInstance()
	{
		static InputManager instance; // Guaranteed to be destroyed.
		// Instantiated on first use.
		return &instance;
	}

private:
	InputManager() {}; // Constructor? (the {} brackets) are needed here.

public:
	InputManager(InputManager const&) = delete;
	void operator=(InputManager const&) = delete;
	std::list < StringInput > strInput;


	void update(sf::RenderWindow &window, sf::Event);
	void draw(sf::RenderWindow &window);
	// Note: Scott Meyers mentions in his Effective Modern
	//       C++ book, that deleted functions should generally
	//       be public as it results in better error messages
	//       due to the compilers behavior to check accessibility
	//       before deleted status
};