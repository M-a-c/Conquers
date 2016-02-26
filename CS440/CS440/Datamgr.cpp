#include "Datamgr.h"
/****Public functions****/

bool DataManager::login_create(struct Player * player)
{
	std::string name = player->name;
	std::string pass = player->password;

	if (create_file(name, "sav") && write_data((name + ".sav"), (name + "," + pass))){
		return true;
	}
	else{
		return false;
	}

}
bool DataManager::login_check(struct Player * player)
{
	std::string username = player->name;
	if (file_exists((player->name + ".sav")) == true){
		return true;
	}
	else{
		return false;
	}
}

bool DataManager::login_delete(struct Player * player){

	std::string username = player->name;
	if (delete_file((username + ".sav")) == true){
		return true;
	}
	else{
		return false;
	}

}

std::string DataManager::login_read(struct Player * player)
{
	std::string username = player->name;
	std::string str_read;
	str_read = read_data((username + ".sav"));
	return str_read;
}

bool DataManager::save_game(struct Game * gamesave, std::string gameIdentifier)
{
	/*dummy place holder until a saved game identification scheme is created*/

	if (create_file(gameIdentifier, "sav") == true)
	{

		/*user A name, password, team color*/
		write_data(gameIdentifier + ".sav", gamesave->userA.name);
		write_data(gameIdentifier + ".sav", gamesave->userA.password);
		write_data(gameIdentifier + ".sav", std::to_string(gamesave->userA.color));

		/*user A resources*/
		write_data(gameIdentifier + ".sav", std::to_string(gamesave->userA.resources.gold));
		write_data(gameIdentifier + ".sav", std::to_string(gamesave->userA.resources.land));
		write_data(gameIdentifier + ".sav", std::to_string(gamesave->userA.resources.soldiers));

		/*user B name, password, team color*/
		write_data(gameIdentifier + ".sav", gamesave->userB.name);
		write_data(gameIdentifier + ".sav", gamesave->userB.password);
		write_data(gameIdentifier + ".sav", std::to_string(gamesave->userB.color));

		/*user B resources*/
		write_data(gameIdentifier + ".sav", std::to_string(gamesave->userB.resources.gold));
		write_data(gameIdentifier + ".sav", std::to_string(gamesave->userB.resources.land));
		write_data(gameIdentifier + ".sav", std::to_string(gamesave->userB.resources.soldiers));

		/*Game parameters*/
		write_data(gameIdentifier + ".sav", std::to_string(gamesave->gameTime));
		write_data(gameIdentifier + ".sav", std::to_string(gamesave->roundTime));
		write_data(gameIdentifier + ".sav", std::to_string(gamesave->era));

		return true;
	}
	else{ return false; }
}

bool DataManager::load_game(std::string gameIdentifier)
{
	if (true )
	{
		return true;
	}
	else{
		return false;
	}

}

bool DataManager::check_game(std::string gameIdentifier)
{
	if ( file_exists((gameIdentifier + ".sav")) == true ) 
	{
		return true;
	}
	else{
		return false;
	}

}

/****Protected functions****/
bool DataManager::create_file(std::string label, std::string ext)
{
	std::ofstream new_file((label + "." + ext).c_str());
	if (new_file.good()){
		new_file.close();
		return true;
	}
	else{
		print( 1, "ofstream failed to create file" );
		return false;
	}

}

bool DataManager::file_exists(std::string filename) 
{
	std::ifstream checkfile(filename.c_str());

	if (checkfile.good()) {
		checkfile.close();
		return true;
	}
	else {
		checkfile.close();
		print( 1, filename + ": does not exist");
		return false;
	}
}


bool DataManager::write_data(std::string filename, std::string text)
{
	//check if file exists before writing
	if (file_exists(filename) == true)
	{
		//object for streaming out data
		std::ofstream dataOut;

		//associated dataOut with existing file
		dataOut.open(filename, std::ofstream::out | std::ofstream::app);

		//check if file actually opened to be written
		if (dataOut.is_open()) {
			//write text to filename selected
			dataOut << (text + "\n\r");
			//Done with input and output operations
			dataOut.close();
		}
		else {
			//returned from file_exists but file was not open
			print(1, filename + " : exists but is not open to be written to");
			return false;
		}
	}
	else{
		print(1, "write to : " + filename + "failed");
		return false;
	}

	return true;
}

std::string DataManager::read_data(std::string filename)
{
	if (file_exists(filename) == true)
	{
		//.txt will be read into fromFile
		std::string fromFile;

		//associate file input stream with local file
		std::ifstream  dataIn(filename);

		//associate input stream with game data file
		dataIn.open(filename);

		//attempt to read from local text file, one line at a time
		if (dataIn.is_open()){

			dataIn.close();
		}
		else{
			//returned from file_exists but file was not open
			return false;
			print(1, filename + " : exists but is not open to be read ");
		}

		dataIn.open(filename);
		std::getline(dataIn, fromFile);
		std::cout << fromFile << '\n';

		return fromFile;
	}
	else{
		print(1, "read from : " + filename + "failed");
		return false;
	}


}

bool DataManager::delete_file(std::string filename)
{
	if (file_exists(filename) == true){
		const char * c = filename.c_str();
		if (remove(c) != 0){
			print(1, "cannot remove file, remove() function failed");
		};
	}
	else{
		print(3, filename + " : cannot be deleted");
	}
	
	return true;
}
	


