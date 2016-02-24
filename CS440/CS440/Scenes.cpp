#ifndef SCENE_H
#define SCENE_H
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <SFML/Audio.hpp>
#include "Failure.hpp"
using std::string;


class Scene:public Failure
{

public:
  
  void setBackground(string filePath)
  {
    if (!background.loadFromFile(filePath)){
      imageFail_important(filePath);
    }
    bk.setTexture(background);
  }

  string name;
  sf::Texture background;
  sf::Sprite bk;

private:
    string getName(){ return name; };

};
#endif