#include "ButtonManager.hpp"

void ButtonManager::addButton(Button *b){
	buttons.push_back(b);
}

//loops through all buttons preforming their updates.
void ButtonManager::MouseMoved(sf::Event &event){
	for (Button * a : buttons){
		a->checkHover(event.mouseMove.x, event.mouseMove.y);
	}
}

GameScene ButtonManager::MouseButtonReleased(sf::Event &event){
	for (Button * a : buttons){
			if (a->mouseClicked() == true){
				std::cout << a->actionString;
				this->returnScene = a->Scene;
				changeScene = 1;
				return a->Scene;
		}
	}
}


//Loops trhough the buttons prefomring their draws.
void ButtonManager::draw(sf::RenderWindow &window){
	//std::cout << buttons.size();
	for (Button *a : buttons){
		window.draw(*a);
	}
}

void ButtonManager::removeAllButtons(){
	unsigned int numberOfButtons = buttons.size();
	for (Button * a: buttons){
		delete(a);
	}

	for (size_t i = 0; i < numberOfButtons; i++){
		buttons.pop_back();
	}
}

int ButtonManager::nextScene(){
	changeScene = 0;
	return returnScene;
}