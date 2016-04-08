#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "MainMenuScene.hpp"
#include "HelpScene.hpp"
#include "LoginScene.hpp"
#include "CreateScene.hpp"
#include "Datamgr.h"
#include "GameOptionsScene.hpp"
#include "GamePlayScene.hpp"
#include "RunningData.hpp"
#include "Questions.hpp"

int main()
{
  sf::RenderWindow window(sf::VideoMode(1280, 720), "Conqueror");   //Creating the render window
  window.setPosition(sf::Vector2i(300, 300));   //Set screen position
  RunningData::getInstance()->reset();
  Questions::getInstance()->gameInit();
  //Music
  sf::Music menu_music;                                 //Music object
  if (!menu_music.openFromFile("Sound/menu_music.ogg")) //Load music
  {
    std::cout << "Sound/menu_music.ogg coundlnt open" << std::endl; //Failure log
  }
  else
  {
    menu_music.play();                                  //Play
    menu_music.setLoop(true);                           //Loop music
  }

  int nextScene = -1;
  while (1)
  {
  
    if (nextScene == 0 || nextScene==MainMenuScene || nextScene == -1)
    {
      MainMenu mainMenu(window, nextScene);
      continue;
    }
    else if (nextScene == LoginScene)
    {
      Login login(window, nextScene);
      continue;
    }
    else if (nextScene == CreateScene)
    {
      Create create(window, nextScene);
      continue;
    }
    else if (nextScene == HelpScene)
    {
      Help help(window, nextScene);
      continue;
    }
	else if (nextScene == OptionsScene)
	{
		GameOptions gameOptions(window, nextScene);
		continue;
	}
	else if (nextScene == PlayGameScene){
		Gameplay gamePlayScene(window, nextScene);
	}
    else
      break;
  }

  menu_music.stop();
  exit(0);
  return 0;
}

