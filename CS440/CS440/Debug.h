#ifndef Debug_H
#define Debug_H
//SFML libs
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>

//Global Var H
#include "Defines.h"

//Built in Libs
#include <time.h>
#include <string.h>
#include <iostream>


//Sourced an example implementaion from http://stackoverflow.com/questions/1008019/c-singleton-design-pattern
class Debug{
	public:
		static Debug& getInstance()
		{
			static Debug instance; // Guaranteed to be destroyed.
			// Instantiated on first use.
			return instance;
		}
		void print(int a,std::string b);
		void debug(int a,std::string b);
		Debug() {};                   // Constructor? (the {} brackets) are needed here.

	private:
		int printsMade = 0;

		// C++ 03
		// ========
		// Dont forget to declare these two. You want to make sure they
		// are unacceptable otherwise you may accidentally get copies of
		// your singleton appearing.
	Debug(Debug const&);              // Don't Implement
	void operator=(Debug const&); // Don't implement

	// C++ 11
	// =======
	// We can use the better technique of deleting the methods
	// we don't want.
	//public:
	//	Debug(Debug const&) = delete;
	//	void operator=(Debug const&) = delete;

};

#endif