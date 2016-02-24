#ifndef FAILURE_H
#define FAILURE_H
#include <iostream>
#include <string>

using std::string;

class Failure
{
public:
  void imageFail_important(string name);  //image loading failure with exit
  void imageFail(string name);  //image loading failure
  void soundFail(string name); //sound loading fail
  void fontFail(string name); //Font fails to load
};
#endif