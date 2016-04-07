/*This class can be instantiated to create new user login, check if a user login exists, and delete a user login.
DataManager class inherits Debug class methods print(int a, string message) 
int a is error level with 0 being the highest priority
message is the error message to be printed

login_create(struct Game * player)
User logins are created by passing address of struct player, nested within current game structure
returns TRUE upon successful creation.
Logins are files written to game directory with the naming convention username.sav 
the contents of the file are two comma separated strings of the form username,password 

login_check(struct Game * player) 
check if login exists by passing address address of struct player, nested within current game structure
searches for username.sav file and determines wether or not that login exists
returns TRUE if the login exists

login_delete(struct Game * player)
delete a login by passing address of struct player , nested within current game structure
deletes the associated username.sav file, returns TRUE upon successful deletion

login_read(struct Game * player)
the username and password associated with a login can be read by passing address of struct player, nested within current game structure
return a string with the username and password as comma separated value

save_game(struct Game * gamesave, std::string gameIdentifier);
save the current game instance and give it a name

load_game(std::string gameIdentifier);
load a previously saved game instance by reading in from saved file and storing to current game struct

check_game(std::string gameIdentifier);
check if game save file extists
*/

#ifndef Datamgr_H
#define Datamgr_H
#include "Debug.h"
#include "stdio.h"
#include <iostream>
#include <fstream>
#include <direct.h>
#include <string.h>

/*Datamanager inherits debugger print(level, error message) 
and debug(level, error message)

protected functions will be used for further file manipulation for DataManager class, 
do not modify these. */

/*player resources, nested within player structure*/
typedef struct Resources{
	int gold;
	int land;
	int soldiers;
}Resources;

/*player structures, player A and B are nested within Game structure*/
typedef struct User{
	std::string name;
	std::string password;
	int color; /*1 = green, 0 = red*/
	Resources resources;
}User;

/*Game structure hold all game and player parameters, this structure can be saveed with game_save() 
  and loaded with game_load() functions located in DataManager class*/
typedef struct Game{
	User userA;
	User userB;
	int roundTime;
	int gameTime;
	int era;
}Game;

class DataManager: public Debug
{
public:
	/*functions to manage the player structure nested within game structure*/
  bool login_create(struct User * player);
  bool login_check(struct User * player);
  bool login_delete(struct User * player);
  std::string login_read(struct User * player);

	/*functions to manage game structure*/
	bool save_game(struct Game * gamesave, std::string gameIdentifier);
	bool load_game(std::string gameIdentifier);
	bool check_game(std::string gameIdentifier);

protected:
	/*please do not modify these*/
	bool create_file(std::string label, std::string ext);
	bool file_exists(std::string filename);
	bool write_data(std::string filename, std::string text);
	std::string read_data(std::string filename);
	bool delete_file(std::string filename);
	
};



#endif




