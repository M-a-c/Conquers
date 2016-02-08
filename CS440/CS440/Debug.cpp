#include "Debug.h"

Debug::Debug(){
	printsMade = 0;
}

void Debug::print(int a,std::string b){
	debug(a,b);
}

void Debug::debug(int a,std::string b){
	if (a < DEBUG_LEVEL){
		std::cout << a;
	}
}