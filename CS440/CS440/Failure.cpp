#include "Failure.hpp"


void Failure::imageFail(string name)
{
  std::cout << name << " iamge could not be loaded" << std::endl;

}

void Failure::soundFail(string name)
{
  std::cout << name << " sound could not be loaded" << std::endl;

}

void Failure::imageFail_important(string name)
{
  std::cout << name << "image  could not be loaded" << std::endl;
  //exit(0);

}

void Failure::fontFail(string name)
{
  std::cout << name << " font could not be loaded" << std::endl;
}