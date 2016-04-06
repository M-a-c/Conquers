#include "ButtonManager.hpp"

ButtonManager::ButtonManager(){

}

//loops through all buttons preforming their updates.
void ButtonManager::MouseMoved(sf::Event &event){
	for (Button &a : buttons){
		a.checkHover(event.mouseMove.x, event.mouseMove.y);
	}
}

void ButtonManager::MouseButtonReleased(sf::Event &event){
	for (Button &a : buttons){
			if (a.mouseClicked() == true){
				std::cout << a.actionString;
			//Some How Register Event to be handled.
		}
	}
}


//Loops trhough the buttons prefomring their draws.
void ButtonManager::draw(){

}

