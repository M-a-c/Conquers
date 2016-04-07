//#include "StringManager.hpp"
//
//void StringManager::addButton(Button *b){
//	stringInputs.push_back(b);
//}
//
////loops through all stringInputs preforming their updates.
//void StringManager::MouseMoved(sf::Event &event){
//	for (Button * a : stringInputs){
//		a->checkHover(event.mouseMove.x, event.mouseMove.y);
//	}
//}
//
//GameScene StringManager::MouseButtonReleased(sf::Event &event){
//	for (Button * a : stringInputs){
//		if (a->mouseClicked() == true){
//			std::cout << a->actionString;
//			this->returnScene = a->Scene;
//			changeScene = 1;
//			return a->Scene;
//		}
//	}
//}
//
//
////Loops trhough the stringInputs prefomring their draws.
//void StringManager::draw(sf::RenderWindow &window){
//	//std::cout << stringInputs.size();
//	for (Button *a : stringInputs){
//		window.draw(*a);
//	}
//}
//
//void StringManager::removeAllStringInput(){
//	unsigned int numberOfStringInput = stringInputs.size();
//	for (Button * a : stringInputs){
//		delete(a);
//	}
//
//	for (size_t i = 0; i < numberOfStringInput; i++){
//		stringInputs.pop_back();
//	}
//}
//
//int StringManager::nextScene(){
//	changeScene = 0;
//	return returnScene;
//}