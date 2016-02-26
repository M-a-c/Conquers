#include "GameOptionsScene.hpp"

GameOptions::GameOptions(sf::RenderWindow &window, int &re_val)
{
  name = "Game options ";                      //Set name
  setBackground("images/menu_image3.jpg");    //Load background
  getImage((float)window.getSize().x,         //Load buttons
    (float)window.getSize().y);         

  //Selections to nothing
  selectedColor = 0;
  selectedTime = 0;
  selectedDur = 0;
  selectedEra = 0;
  selectedUnits = 0;                              
  re_val = update(window);                    //update loop with return value
  return;                                     //return from MainMenu
}

GameOptions::~GameOptions()
{
  std::cout << "Deconstructor for GameOptions";
}

//Updating the loop
int GameOptions::update(sf::RenderWindow &window)
{
  //While the window open
  while (window.isOpen())
  {
    sf::Event event;

    //Look for event
    while (window.pollEvent(event))
    {

      switch (event.type)
      {
        //Event for hitting the x
      case sf::Event::Closed:
        window.close();
        exit(0);
        break;

        //Mouse over button
      case sf::Event::MouseMoved:
        button[0].checkHover(event.mouseMove.x, event.mouseMove.y);
        button[1].checkHover(event.mouseMove.x, event.mouseMove.y);
        button[2].checkHover(event.mouseMove.x, event.mouseMove.y);
        button[3].checkHover(event.mouseMove.x, event.mouseMove.y);
        button[4].checkHover(event.mouseMove.x, event.mouseMove.y);
        button[5].checkHover(event.mouseMove.x, event.mouseMove.y);
        button[6].checkHover(event.mouseMove.x, event.mouseMove.y);
        button[7].checkHover(event.mouseMove.x, event.mouseMove.y);
        button[8].checkHover(event.mouseMove.x, event.mouseMove.y);
        button[9].checkHover(event.mouseMove.x, event.mouseMove.y);
        button[10].checkHover(event.mouseMove.x, event.mouseMove.y);
        button[11].checkHover(event.mouseMove.x, event.mouseMove.y);
        button[12].checkHover(event.mouseMove.x, event.mouseMove.y);
        opButton[0].checkHover(event.mouseMove.x, event.mouseMove.y);
        opButton[1].checkHover(event.mouseMove.x, event.mouseMove.y);
        break;

        //Click button
      case::sf::Event::MouseButtonReleased:
        //Play button
        if (opButton[0].mouseClicked() == true)
        {
          if (selectedColor > 0 && selectedDur > 0 && selectedTime > 0 && selectedUnits > 0 && selectedEra > 0)
            std::cout << "Playing game" << std::endl;
            return 5;
        }
        //back button
        else if (opButton[1].mouseClicked() == true)
        {
          std::cout << "Back" << std::endl;
          return 0;
        }

        buttonSelectionCheck();//Function that will check selections
        
        break;

      }

    }

    //Clearing and drawing
    window.clear();
    draw(window);
    window.display();
  }
  return 0;
}


//Function thta will load images
void GameOptions::getImage(float width, float height)
{
  //Getting prompt and color
  if (!texture[0].loadFromFile("images/b_green.png", sf::IntRect(0, 0, 200, 100)))
    imageFail_important("images/b_green.png");
  if (!texture[1].loadFromFile("images/b_red.png", sf::IntRect(0, 0, 200, 100)))
    imageFail_important("images/b_red.jpg");
  if (!texture[2].loadFromFile("images/color.png", sf::IntRect(0, 0, 200, 100)))
    imageFail_important("images/color.png");

  //Getting prompt and era
  if (!texture[3].loadFromFile("images/era.png", sf::IntRect(0, 0, 200, 100)))
    imageFail_important("images/era.png");
  if (!texture[4].loadFromFile("images/b_ww2.png", sf::IntRect(0, 0, 200, 100)))
    imageFail_important("images/b_ww2.png");
  if (!texture[5].loadFromFile("images/b_roman.png", sf::IntRect(0, 0, 220, 100)))
    imageFail_important("images/b_roman.jpg");

  //Getting prompt and duration
  if (!texture[6].loadFromFile("images/duration.png", sf::IntRect(0, 0, 280, 100)))
    imageFail_important("images/duration.png");
  if (!texture[7].loadFromFile("images/b_10min.png", sf::IntRect(0, 0, 200, 100)))
    imageFail_important("images/b_10min.png");
  if (!texture[8].loadFromFile("images/b_5min.png", sf::IntRect(0, 0, 200, 100)))
    imageFail_important("images/b_5min.png");
  if (!texture[9].loadFromFile("images/b_min.png", sf::IntRect(0, 0, 200, 100)))
    imageFail_important("images/b_min.jpg");

  //Getting prompt and time
  if (!texture[10].loadFromFile("images/time.png", sf::IntRect(0, 0, 200, 100)))
    imageFail_important("images/time.png");
  if (!texture[11].loadFromFile("images/b_hr.png", sf::IntRect(0, 0, 200, 100)))
    imageFail_important("images/b_hr.png");
  if (!texture[12].loadFromFile("images/b_12hr.png", sf::IntRect(0, 0, 200, 100)))
    imageFail_important("images/b_12hr.png");
  if (!texture[13].loadFromFile("images/b_24hr.png", sf::IntRect(0, 0, 200, 100)))
    imageFail_important("images/b_24hr.jpg");

  //Getting prompt and unit
  if (!texture[14].loadFromFile("images/unit.png", sf::IntRect(0, 0, 200, 100)))
    imageFail_important("images/unit.png");
  if (!texture[15].loadFromFile("images/b_100.png", sf::IntRect(0, 0, 200, 100)))
    imageFail_important("images/b_100.png");
  if (!texture[16].loadFromFile("images/b_50.png", sf::IntRect(0, 0, 200, 100)))
    imageFail_important("images/b_50.png");
  if (!texture[17].loadFromFile("images/b_25.png", sf::IntRect(0, 0, 200, 100)))
    imageFail_important("images/b_25.jpg");
  
  //Getting prompt and other
  if (!texture[18].loadFromFile("images/b_play.png", sf::IntRect(0, 0, 180, 60)))
    imageFail_important("images/b_help.png");
  if (!texture[19].loadFromFile("images/b_back.png", sf::IntRect(0, 0, 180, 60)))
    imageFail_important("images/b_exit.png");
  if (!texture[20].loadFromFile("images/b_sword.png", sf::IntRect(0, 0, 200, 100)))
    imageFail_important("images/b_login.png");
 

  //Loading into sprites and setting position

  //Play and back button
  opButton[0].setTexture(texture[18]);
  opButton[0].setPosition(sf::Vector2f((width / 10)*9 - (180 / 2), (height / 4)));
  opButton[1].setTexture(texture[19]);
  opButton[1].setPosition(sf::Vector2f((width /10)*9 - (180 / 2), (height / 4)*2));
  
  //Prompts
  prompt[0].setTexture(texture[2]);
  prompt[1].setTexture(texture[3]);
  prompt[2].setTexture(texture[6]);
  prompt[3].setTexture(texture[10]);
  prompt[4].setTexture(texture[14]);
  prompt[0].setPosition(sf::Vector2f((width / 10) - (200 / 2), (height / 6) ));
  prompt[1].setPosition(sf::Vector2f((width / 10) - (200 / 2), (height / 6)*2 ));
  prompt[2].setPosition(sf::Vector2f((width / 10) - (280 / 2)+4, (height / 6)*3 ));
  prompt[3].setPosition(sf::Vector2f((width / 10) - (200 / 2), (height / 6)*4 ));
  prompt[4].setPosition(sf::Vector2f((width / 10) - (200 / 2), (height / 6)*5 ));

  //Color
  button[0].setTexture(texture[0]);
  button[1].setTexture(texture[1]);
  button[0].setPosition(sf::Vector2f((width / 10)*3 - (200 / 2), (height / 6)));
  button[1].setPosition(sf::Vector2f((width / 10)*5 - (200 / 2), (height / 6)));

  //Era
  button[2].setTexture(texture[4]);
  button[3].setTexture(texture[5]);
  button[2].setPosition(sf::Vector2f((width / 10)*3 - (200 / 2), (height / 6) * 2));
  button[3].setPosition(sf::Vector2f((width / 10)*5 - (200 / 2), (height / 6) * 2));

  //Time
  button[4].setTexture(texture[11]);
  button[5].setTexture(texture[12]);
  button[6].setTexture(texture[13]);
  button[4].setPosition(sf::Vector2f((width / 10) * 3 - (200 / 2), (height / 6) * 4));
  button[5].setPosition(sf::Vector2f((width / 10) * 5 - (200 / 2), (height / 6) * 4));
  button[6].setPosition(sf::Vector2f((width / 10) * 7 - (200 / 2), (height / 6) * 4));

  //Duration
  button[7].setTexture(texture[7]);
  button[8].setTexture(texture[8]);
  button[9].setTexture(texture[9]);
  button[7].setPosition(sf::Vector2f((width / 10) * 3 - (200 / 2), (height / 6) * 3));
  button[8].setPosition(sf::Vector2f((width / 10) * 5 - (200 / 2), (height / 6) * 3));
  button[9].setPosition(sf::Vector2f((width / 10) * 7 - (200 / 2), (height / 6) * 3));

  //Unit
  button[10].setTexture(texture[15]);
  button[11].setTexture(texture[16]);
  button[12].setTexture(texture[17]);
  button[10].setPosition(sf::Vector2f((width / 10) * 3 - (200 / 2), (height / 6) * 5));
  button[11].setPosition(sf::Vector2f((width / 10) * 5 - (200 / 2), (height / 6) * 5));
  button[12].setPosition(sf::Vector2f((width / 10) * 7 - (200 / 2), (height / 6) * 5));

  //swords
  for (int i = 0; i < 5; i++)
  {
    sword[i].setTexture(texture[20]);
    sword[i].setPosition(sf::Vector2f(width + 100, height + 100) );
  }
}


//drawing
void GameOptions::draw(sf::RenderWindow &window)
{
  window.draw(bk);                  //Draw bk
  for (int i = 0; i < 13; i++)      //Draw buttons
    window.draw(button[i]);
  for (int i = 0; i < 2; i++)       //Drawing option button
    window.draw(opButton[i]);
  for (int i = 0; i < 5; i++)       //Drawing prompt + swords
  {
    window.draw(prompt[i]);
    window.draw(sword[i]);
  }
}

void GameOptions::buttonSelectionCheck()
{

  //Color Selection
  if (button[0].mouseClicked() == true)
  {
    selectedColor = 1;
    sword[0].setPosition(button[0].getPosition());
  }
  else if (button[1].mouseClicked() == true)
  {
    selectedColor = 2;
    sword[0].setPosition(button[1].getPosition());

  }

  //Era Selection
  if (button[2].mouseClicked() == true)
  {
    selectedEra = 1;
    sword[1].setPosition(button[2].getPosition());
  }
  else if (button[3].mouseClicked() == true)
  {
    selectedEra = 2;
    sword[1].setPosition(button[3].getPosition());
  }

  //Time Selection
  if (button[4].mouseClicked() == true)
  {
    selectedTime = 1;
    sword[2].setPosition(button[4].getPosition());
  }
  else if (button[5].mouseClicked() == true)
  {
    selectedTime = 2;
    sword[2].setPosition(button[5].getPosition());
  }
  else if (button[6].mouseClicked() == true)
  {
    selectedTime = 3;
    sword[2].setPosition(button[6].getPosition());
  }

  //Duration Selection
  if (button[7].mouseClicked() == true)
  {
    selectedDur = 1;
    sword[3].setPosition(button[7].getPosition());
  }
  else if (button[8].mouseClicked() == true)
  {
    selectedDur = 2;
    sword[3].setPosition(button[8].getPosition());
  }
  else if (button[9].mouseClicked() == true)
  {
    selectedDur = 3;
    sword[3].setPosition(button[9].getPosition());
  }

  //Unit Selection
  if (button[10].mouseClicked() == true)
  {
    selectedUnits = 1;
    sword[4].setPosition(button[10].getPosition());
  }
  else if (button[11].mouseClicked() == true)
  {
    selectedUnits = 2;
    sword[4].setPosition(button[11].getPosition());
  }
  else if (button[12].mouseClicked() == true)
  {
    selectedUnits = 3;
    sword[4].setPosition(button[12].getPosition());
  }



  

}