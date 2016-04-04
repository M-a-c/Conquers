#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Failure.hpp"
#include "Scenes.cpp"
#include "Button.hpp"
#include "Debug.h"


class StringInput {
	public:
		StringInput();
		~StringInput();
		char isTypableText(sf::Keyboard::Key a);
		void hide(bool a);
		


		void setPosition(sf::Vector2f p);
		void setPosition(float x,float y);

		void setOuterBoxColor(sf::Color c);
		void setInnerBoxColor(sf::Color c);
		
		void setOuterBoxSize(sf::Vector2f v);


	private:
		bool selected;
		bool hideOutput;

		sf::RectangleShape outerBox;
		sf::RectangleShape innerBox;


		sf::Vector2f position;

		sf::Text text;
		
		std::string appendto;

		std::string input;
		std::string obfisticated;

		int maxInputSize;
};