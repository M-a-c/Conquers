#include "Datamgr.h"

void GameData:: write_data(void)
{
	std::ofstream dataOut;

	//associate file output stream with local file
	dataOut.open("gameData.txt");

	if (dataOut.is_open()) {
		//write text to local file
		dataOut << "this is the first line \n\r";
		dataOut << "  this is the second line \n";
		//Done with input and output operations
		dataOut.close();
	}
	else {
		std::cout << "local game file was not opened";
	}
}

void GameData::read_data(void){
	//.txt will be read into fromFile
	std::string fromFile;

	//associate file input stream with local file
	std::ifstream  fileIn("gameData.txt");

	//associate input stream with game data file
	fileIn.open("gameData.txt");

	//attempt to read from local text file, one line at a time
	if (fileIn.is_open()){

		fileIn.close();
	}
	else{
		std::cout << "local game file cannot be opened";
	}

	fileIn.open("gameData.txt");
	std::getline(fileIn, fromFile);
	std::cout << fromFile << '\n';
}