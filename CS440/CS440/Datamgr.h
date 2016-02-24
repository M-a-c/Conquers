/*Data Manager defines a game data class and provideds functions to read and write
  game data to and from a local text file. */

#include "stdio.h"
#include <string>
#include <iostream>
#include <fstream>
#include <direct.h>

/*Used to create a directory associated with game, create txt files for resources, read and write resource values to */

class DataManager{
	
};

/*Database of stream objects to be associated with text files*/
struct DataBase{

		std::ofstream gold;
		std::ofstream land;
		std::ofstream soldiers;

};

class GameData{

public:
	void write_data(void);
	void read_data(void);

};

