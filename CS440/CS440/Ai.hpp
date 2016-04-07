#include "Player.hpp"

class Ai :public Player
{
public:
  Ai();
  ~Ai();
  bool doOnce;
  void runAI();
  void winWar(int gold, int land, int worker);
  
private:
  sf::Clock roundTime;
};