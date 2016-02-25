/*This class can be instantiated to create new user login, check if a user login exists, and delete a user login.
DataManager class inherits Debug class methods print(int a, string message) 
int a is error level with 0 being the highest priority
message is the error message to be printed

login_create("username", "password")
User logins are created with by passing a username and password, both of type string.
returns TRUE upon successful creation.
Logins are files written to game directory with the naming convention username.sav 
the contents of the file are two comma separated strings of the form username,password 

login_check("username") 
searches for username.sav file and determines wether or not that login exists
returns TRUE if the login exists

login_delete("username")
deletes the associated username.sav file, returns TRUE upon successful deletion

csv for username and password, (accounts list, used to check if valid acct)
additional files of only valid user name and saved data(saved data for each account, their own txt file per acct)*/

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

class DataManager: public Debug
{

public:

	bool login_create(std::string name, std::string pass);
	bool login_check(std::string username);
	bool login_delete(std::string username);

protected:
	bool create_file(std::string label, std::string extension);
	bool file_exists(std::string filename);
	bool write_data(std::string filename, std::string text);
	std::string read_data(std::string filename);
	bool delete_file(std::string filename);
	
};

#endif




