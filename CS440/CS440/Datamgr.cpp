#include "Datamgr.h"
/*
create login function, return 1 if created succesfully created, else 0 , also print out conflict or name already exists
check login function boolean return 1 if valid, 
delete login function, take in login and pass, find it in file 1, else 0 if not found , prints to screen
all take in string name and string password as inputs 
when users are created, blank_name.sav delete_name.sav, (.sav is a file descriptor) 

csv for username and password, (accounts list, used to check if valid acct)
additional files of only valid user name and saved data(saved data for each account, their own txt file per acct)

this.debug, first argument you send it integer saying what level of debug it is (lower number, higher priority, 0 is critical*/

/*create a file with a custom label and extension within the project folder*/

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

bool DataManager::login_create(std::string name, std::string pass)
{
	if ( create_file(name, "sav") && write_data((name + ".sav") , (name + "," + pass)) ){
		return true;
	}
	else{ 
		return false; 
	}

}
bool DataManager::login_check(std::string username)
{ 
	if ( file_exists((username + ".sav")) == true ){
		return true;
	}
	else{ 
		return false; 
	}
}

bool DataManager::login_delete(std::string username){ 
	
	if (delete_file((username + ".sav")) == true){
		return true;
	}
	else{
		return false;
	}

}