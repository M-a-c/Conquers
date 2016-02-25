#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "MainMenuScene.hpp"
#include "HelpScene.hpp"
#include "LoginScene.hpp"
#include "CreateScene.hpp"
#include "Datamgr.h"

int main()
{
  sf::RenderWindow window(sf::VideoMode(1280, 720), "Conqueror");   //Creating the render window
  window.setPosition(sf::Vector2i(300, 300));   //Set screen position

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
  
    if (nextScene == 0 || nextScene == -1)
    {
      MainMenu mainMenu(window, nextScene);
      continue;
    }
    else if (nextScene == 1)
    {
      Login login(window, nextScene);
      continue;
    }
    else if (nextScene == 2)
    {
      Create create(window, nextScene);
      continue;
    }
    else if (nextScene == 3)
    {
      Help help(window, nextScene);
      continue;
    }
    else
      break;
  }

  menu_music.stop();
  exit(0);
  return 0;
}

