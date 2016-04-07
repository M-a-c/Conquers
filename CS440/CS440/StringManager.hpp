////Singelton design pattern.
////Sourced from.
////http://stackoverflow.com/questions/1008019/c-singleton-design-pattern
//
//#pragma once 
//#include <list>
//#include "StringInput.hpp"
//
//class StringManager {
//public:
//	static StringManager* getInstance()
//	{
//		static StringManager instance; // Guaranteed to be destroyed.
//		// Instantiated on first use.
//		return &instance;
//	}
//private:
//	StringManager() {};                  // Constructor? (the {} brackets) are needed here.
//
//public:
//	StringManager(StringManager const&) = delete;
//	void operator=(StringManager const&) = delete;
//	std::list < StringInput * > StringInputs;
//
//	void addStringInput(StringInput *b);
//	void MouseMoved(sf::Event &event);
//	GameScene MouseStringInputReleased(sf::Event &event);
//	void removeAllStringInputs();
//
//	void draw(sf::RenderWindow &window);
//
//	// if(StringManager.)
//
//	// Note: Scott Meyers mentions in his Effective Modern
//	//       C++ book, that deleted functions should generally
//	//       be public as it results in better error messages
//	//       due to the compilers behavior to check accessibility
//	//       before deleted status
//};