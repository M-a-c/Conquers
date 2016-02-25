/*check login function boolean return 1 if valid, 
create login function, return 1 if created succesfully created, else 0, also print out conflict or name already exists
delete login function, take in login and pass, find it in file 1, else 0 if not found, prints to screen
all take in string name and string password as inputs
when users are created, blank_name.sav delete_name.sav, (.sav is a file descriptor)

csv for username and password, (accounts list, used to check if valid acct)
additional files of only valid user name and saved data(saved data for each account, their own txt file per acct)

data just says the class it is, has all information to re-read it.
a data item (like a scene) a data item has a write method, sends the data (ints and strings lists) to datamanager*/
#ifndef Datamgr_H
#define Datamgr_H
#include "Debug.h"
#include "stdio.h"
#include <iostream>
#include <fstream>
#include <direct.h>
#include <string.h>



/*Datamanager inherits debugger print(level, error message) 
and debug(level, error message)*/

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




