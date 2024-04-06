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
    game.run(game);

    /*
    // Get a reference to the random number generator
    std::mt19937& rng = game.getRNG();

    // Use rng to generate random numbers
    std::uniform_real_distribution <float> dist(0, 1);
    float randomNumber = dist(rng);

    // Output the generated random number
    std::cout << "Random number: " << randomNumber << std::endl;
    */

    
    std::random_device rd;
    std::mt19937 mt(rd());

    // Define the range for the random integer
    int min = 1;
    int max = 10;

    // Create a uniform integer distribution for the range [min, max]
    std::uniform_int_distribution<int> dist(min, max);

    // Generate random numbers using mt19937 and dist
    for (int i = 0; i < 5; ++i) {
        int random_number = dist(mt); // Generate a random number
        std::cout << "Random number " << i + 1 << ": " << random_number << std::endl;
    }

   


  

   

    return 0;

}
