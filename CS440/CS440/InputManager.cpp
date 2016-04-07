#include "InputManager.hpp"

void InputManager::update(sf::RenderWindow &window, sf::Event event){

	switch (event.type)
	{
		//Event for hitting the x
		case sf::Event::Closed:
			window.close();
			exit(0);
			break;

		//Mouse over button
		case sf::Event::MouseMoved:
			ButtonManager::getInstance()->MouseMoved(event);
			break;

		//Click button
		case::sf::Event::MouseButtonReleased:
			ButtonManager::getInstance()->MouseButtonReleased(event);
			for (auto L : strInput){
				
			}

			break;


	}
}

void InputManager::draw(sf::RenderWindow &window){
	ButtonManager::getInstance()->draw(window);
}
 