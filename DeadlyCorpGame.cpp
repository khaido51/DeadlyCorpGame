// DeadlyCorpGame.cpp : Defines the entry point for the application.
//

#include "DeadlyCorpGame.h"
#include "Game.h"
#include "Item.h"
#include "Moon.h"
#include "MoonManager.h"
#include "AbstractMoon.h"
#include "ItemManager.h"
#include <iostream>
#include <string>
#include <list>
#include "util.h"




int main()
{

    //Initialize to default value for each variable when the game start
    /*
    int day = 1;
    int balance = 500;
    int cargo = 0;
    int quota = 150;
    int numberOfEmployees = 4;
    int maxDayCycle = 4;
    */
    MoonManager moonManager;
    ItemManager itemManager;


    //Game game(cargo, balance, day, quota, numberOfEmployees, maxDayCycle,itemManager, moonManager);
   

    Game game;
    game.initializeGame();
    game.run();

    /*
    // Get a reference to the random number generator
    std::mt19937& rng = game.getRNG();

    // Use rng to generate random numbers
    std::uniform_real_distribution <float> dist(0, 1);
    float randomNumber = dist(rng);

    // Output the generated random number
    std::cout << "Random number: " << randomNumber << std::endl;
    */

    
  

   


  

   

    return 0;

}
