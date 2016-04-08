#include "Datamgr.h"

/****Public functions****/

bool DataManager::login_create(struct User * player)
{
	std::string name = player->name;
	std::string pass = player->password;

	if (create_file(name, "sav") && write_data((name + ".sav"), (name + " " + pass))){
		return true;
	}
	else{
		return false;
	}

}

bool DataManager::login_check(struct User * player)
{
	std::string username = player->name;
	if (file_exists((player->name + ".sav")) == true){
		return true;
	}
	else{
		return false;
	}
}

bool DataManager::login_delete(struct User * player){

	std::string username = player->name;
	if (delete_file((username + ".sav")) == true){
		return true;
	}
	else{
		return false;
	}

}

std::string DataManager::login_read(struct User * player)
{
	std::string username = player->name;
	std::string str_read;
	str_read = read_data((username + ".sav"));
	return str_read;
}

bool DataManager::saveRunningData(std::string gameIdentifier)
{
	/*dummy place holder until a saved game identification scheme is created*/

	/*create pointer to current game data running*/
	RunningData * rD;
	rD = RunningData::getInstance();
	
	if ( file_exists(gameIdentifier + ".sav") == true )
	{

		/*user A name, password, team color*/
		//write_data(gameIdentifier + ".sav", rD->PlayerName + "1n");
		//write_data(gameIdentifier + ".sav", rD->PlayerPassword + "1p");

		write_data(gameIdentifier + ".sav", std::to_string(rD->SelectedRoundTime));
		write_data(gameIdentifier + ".sav", std::to_string(rD->SelectedGameTime));
		write_data(gameIdentifier + ".sav", std::to_string(rD->SelectedColor));
		write_data(gameIdentifier + ".sav", std::to_string(rD->SelectedEra));
		write_data(gameIdentifier + ".sav", std::to_string(rD->SelectedUnitNumber));

		write_data(gameIdentifier + ".sav", std::to_string(rD->currentGameTime));

		write_data(gameIdentifier + ".sav", std::to_string(rD->questionIndex));

		write_data(gameIdentifier + ".sav", std::to_string(rD->score));
		write_data(gameIdentifier + ".sav", std::to_string(rD->gold));
		write_data(gameIdentifier + ".sav", std::to_string(rD->population));
		write_data(gameIdentifier + ".sav", std::to_string(rD->land));
		write_data(gameIdentifier + ".sav", std::to_string(rD->conquerCount));
		write_data(gameIdentifier + ".sav", std::to_string(rD->color));
		write_data(gameIdentifier + ".sav", std::to_string(rD->siegeUnit));
		write_data(gameIdentifier + ".sav", std::to_string(rD->cavalryUnit));
		write_data(gameIdentifier + ".sav", std::to_string(rD->infantryUnit));
		write_data(gameIdentifier + ".sav", std::to_string(rD->maxMilitary));
		write_data(gameIdentifier + ".sav", std::to_string(rD->maxPopulaiton));
		write_data(gameIdentifier + ".sav", std::to_string(rD->military));//combo of units
		write_data(gameIdentifier + ".sav", std::to_string(rD->turnCounter));

		write_data(gameIdentifier + ".sav", std::to_string(rD->Ai_score));
		write_data(gameIdentifier + ".sav", std::to_string(rD->Ai_gold));
		write_data(gameIdentifier + ".sav", std::to_string(rD->Ai_population));
		write_data(gameIdentifier + ".sav", std::to_string(rD->Ai_land));
		write_data(gameIdentifier + ".sav", std::to_string(rD->Ai_conquerCount));
		write_data(gameIdentifier + ".sav", std::to_string(rD->Ai_color));
		write_data(gameIdentifier + ".sav", std::to_string(rD->Ai_siegeUnit));
		write_data(gameIdentifier + ".sav", std::to_string(rD->Ai_cavalryUnit));
		write_data(gameIdentifier + ".sav", std::to_string(rD->Ai_infantryUnit));
		write_data(gameIdentifier + ".sav", std::to_string(rD->Ai_maxMilitary));
		write_data(gameIdentifier + ".sav", std::to_string(rD->Ai_maxPopulaiton));
		write_data(gameIdentifier + ".sav", std::to_string(rD->Ai_military));//combo of units
		write_data(gameIdentifier + ".sav", std::to_string(rD->Ai_cavalryUnit));
		write_data(gameIdentifier + ".sav", "\n\r");

		return true;
	}
	else{ return false; }
}

bool DataManager::load_game(std::string gameIdentifier)
{
	if ( file_exists(gameIdentifier + ".sav") == true )
	{

		RunningData * rD;
		rD = RunningData::getInstance();

		string Pname;
		string Ppass;

		/*selected values*/
		float SRtime = 0.0f;
		float SGtime = 0.0f;
		int Scolor = 0;
		int Sera = 0;
		int Unumber = 0;


		/*current values*/
		float CGtime = 0.0f;
		int Qindex = 0;

		int scr = 0;
		int gld = 0;
		int pop = 0;
		int lnd = 0;
		int Concount = 0;
		int clr = 0;
		int Sunit = 0;
		int Cavunit = 0;
		int infUnit = 0;
		int maxMil = 0;
		int maxPop = 0;
		int mil = 0;
		bool turnCnt;

		int Aiscore = 0;
		int Aigold = 0;
		int Aipop = 0;
		int Ailnd = 0;
		int AicCount = 0;
		int Aicolor = 0;
		int AisiegeUnit = 0;
		int AicavalryUnit = 0;
		int AiinfantryUnit = 0;
		int AimaxMilitary = 0;
		int AimaxPop = 0;
		int Aimil = 0;
		int AicavUnit = 0;

		//.txt will be read into fromFile
		std::string fromFile;

		//associate file input stream with local file
		std::ifstream  dataIn(gameIdentifier);

		//associate input stream with game data file
		dataIn.open(gameIdentifier);

		dataIn >> Pname >> Ppass >> SRtime >> SGtime >> Scolor >> Sera >> Unumber >> CGtime >> Qindex >> scr >> gld >> pop >> lnd >> Concount;
		dataIn >> clr >> Sunit >> Cavunit >> infUnit >> maxMil >> maxPop >> turnCnt >> Aiscore >> Aigold >> Aipop >> Ailnd >> AicCount;
		dataIn >> Aicolor >> AisiegeUnit >> AimaxPop >> Aimil >> AicavUnit;
		dataIn.close();

		rD->PlayerName = Pname;
		rD->PlayerPassword = Ppass;

		rD->SelectedRoundTime = SRtime;
		rD->SelectedGameTime = SGtime;
		rD->SelectedColor = Scolor;
		rD->SelectedEra = Sera;
		rD->SelectedUnitNumber = Unumber;

		rD->currentGameTime = CGtime;
		rD->questionIndex = Qindex;

		rD->score = scr;
		rD->gold = gld;
		rD->population = pop;
		rD->land = lnd;
		rD->conquerCount = Concount;
		rD->color = clr;
		rD->siegeUnit = Sunit;
		rD->cavalryUnit = Cavunit;
		rD->infantryUnit = infUnit;
		rD->maxMilitary = maxMil;
		rD->maxPopulaiton = maxPop;
		rD->military = mil;
		rD->turnCounter = turnCnt;



		rD->Ai_score = Aiscore;
		rD->Ai_gold = Aigold;
		rD->Ai_population = Aipop;
		rD->Ai_land = Ailnd;
		rD->Ai_conquerCount = AicCount;;
		rD->Ai_color = Aicolor;
		rD->Ai_siegeUnit = AisiegeUnit;
		rD->Ai_cavalryUnit = AicavalryUnit;
		rD->Ai_infantryUnit = AiinfantryUnit;
		rD->Ai_maxMilitary = AimaxMilitary;
		rD->Ai_maxPopulaiton = AimaxPop;
		rD->Ai_military = Aimil;
		rD->Ai_cavalryUnit = AicavUnit;

		return true;
	}
	else{
		return false;
	}

}

bool DataManager::has_save(std::string gameIdentifier)
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
			dataOut << (text + " ");
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

		if (!dataIn)
		{
			Debug db;
			db.print(1, "Done fucked up");
		}
			return fromFile;
		}
		else{
			print(1, "read from : " + filename + "failed");
			return false;
		}


	}

bool DataManager::delete_file(std::string filename){

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
	


