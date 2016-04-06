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
		//ButtonManager::getInstance()->MouseMoved(event);
		break;

		//Click button
	case::sf::Event::MouseButtonReleased:
		//ButtonManager::getInstance()->MouseButtonReleased(event);

		//Button Event move them somehow to the button manager, list of stuff. controls it.
	//case sf::Event::KeyReleased:
	//	switch (event.key.code)
	//	{
	//		//Up arrow
	//	case sf::Keyboard::Up:
	//		moveUp();
	//		break;

	//		//Down arrow
	//	case sf::Keyboard::Down:
	//		moveDown();
	//		break;

	//		//W button
	//	case sf::Keyboard::W:
	//		moveUp();
	//		break;

	//		//S button
	//	case sf::Keyboard::S:
	//		moveDown();
	//		break;

	//		//Return button
	//	case sf::Keyboard::Return:
	//		if (returnPress() == 0)
	//		{
	//			std::cout << "Login\n";
	//			return 1;
	//		}
	//		else if (returnPress() == 1)
	//		{
	//			std::cout << "New\n";
	//			return 2;
	//		}
	//		else if (returnPress() == 2)
	//		{
	//			std::cout << "Help\n";
	//			return 3;
	//		}
	//		else if (returnPress() == 3)
	//		{
	//			std::cout << "Exit\n";
	//			window.close();
	//			exit(0);
	//		}

	//	}
	//	break;
		break;
	}
}

void InputManager::draw(sf::RenderWindow &window){



}
