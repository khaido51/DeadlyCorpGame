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
    int day = 1;
    int balance = 500;
    int cargo = 0;
    int quota = 150;
    int numberOfEmployees = 4;
    int maxDayCycle = 4;
    int count = 0; 
    MoonManager moonManager;
    ItemManager itemManager;


    Game game(cargo, balance, day, quota, numberOfEmployees, maxDayCycle,itemManager, moonManager);
   

    std::string moonInGame = "";
    MoonWeather weatherInMoon{};
    AbstractMoon* abstractMoon;
    Moon moon;

    game.createItems(itemManager);
    game.createMoons(moonManager);
    game.initializeGame(moonInGame);
    

    /*
    // Get a reference to the random number generator
    std::mt19937& rng = game.getRNG();

    // Use rng to generate random numbers
    std::uniform_real_distribution <float> dist(0, 1);
    float randomNumber = dist(rng);

    // Output the generated random number
    std::cout << "Random number: " << randomNumber << std::endl;
    */

    
    
    std::vector<std::string> orbitingPhase = { "moons", "store", "route", "inventory", "buy","land", "exit" };
    std::vector<std::string> landingPhase = { "moons", "store","inventory", "buy","land", "exit", "send", "sell", "leave", "route"};


  

    std::string command = "";
    std::vector<std::string> arguments;
    bool orbitPhase = true;
    bool foundPhase = false;


    while (true) {
        //user input
        std::cout << ">";
        std::getline(std::cin >> std::ws, command);
        util::splitArguments(command, arguments);
        //change to lower case
        util::lower(command);
        //check for orbiting phase
        if (orbitPhase == true) {
            //loop through orbitingPhase
            for (auto phase : orbitingPhase) {
                if (command == phase) {
                    foundPhase = true;
                    if (command == "moons") {
                        moonManager.processCommands(command, moonInGame, balance, arguments, weatherInMoon);
                    }
                    else if (command == "store") {
                        itemManager.processCommand(command, balance, arguments, cargo, quota);
                    }
                    else if (command == "inventory") {
                        itemManager.processCommand(command, balance, arguments, cargo, quota);
                    }
                    else if (command == "route") {
                        moonManager.processCommands(command, moonInGame, balance, arguments, weatherInMoon);
                    }
                    else if (command == "buy") {
                        itemManager.processCommand(command, balance, arguments, cargo, quota);
                    }
                    else if (command == "land") {
                        game.processCommand(command, moonInGame, weatherInMoon);
                        game.setOrbitingMoon(moonInGame);
                        orbitPhase = false;
                        break;
                    }
                }
            }
        }
        else if (orbitPhase == false) {
            for (auto phase : landingPhase) {
                if (command == phase) {
                    foundPhase = true;
                    
                    if (command == "moons") {
                        moonManager.processCommands(command, moonInGame, balance, arguments, weatherInMoon);
                    }
                    else if (command == "store") {
                        itemManager.processCommand(command, balance, arguments, cargo, quota);
                    }
                    else if (command == "inventory") {
                        itemManager.processCommand(command, balance, arguments, cargo, quota);
                    }
                    else if (command == "buy") {
                        itemManager.processCommand(command, balance, arguments, cargo, quota);
                    }
                    else if (command == "sell") {
                        if (moonInGame != "corporation") {
                            std::cout << "You can not use sell command in this moon " << std::endl;
                        }
                        else {
                            moon.sellCargo(game, count);
                        }
                    }
                    else if (command == "send") {
                        if (moonInGame == "corporation") {
                            std::cout << "You can not use send command in this moon" << std::endl;
                        }
                        else {
                            if (arguments.empty()) {
                                std::cout << "Bad command, the syntax is: send numberOfEmployees" << std::endl;
                            }
                            count = stoi(arguments[0]);
                            moon.sendEmployees(game, count);
                        }  
                    }
                    else if (command == "leave") {
                        moon.onDayBegin(game);
                        orbitPhase = true;
                        break;
                    }
                    else if (command == "land") {
                        std::cout << "You already landed on " << game.getOrbitingMoon() << std::endl;
                    }
                    else if (command == "route") {
                        std::cout << "Can not use this command" << std::endl;

                    }
                }
            }
        }
        else {
            foundPhase = false;
        }
        if (!foundPhase) {
            std::cout << "Invalid Command!!" << std::endl;
        }

    }

    return 0;

}
