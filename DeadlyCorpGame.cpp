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


    std::string moonInGame = "";
    MoonWeather weatherInMoon;

    Game game(cargo, balance, day, quota, numberOfEmployees, maxDayCycle);
    MoonManager moonManager;
    ItemManager itemManager;
    AbstractMoon* abstractMoon;
    Moon moon;


    game.initializeGame();
    game.createItems(itemManager);
    game.createMoons(moonManager);



    std::vector<std::string> orbitingPhase = { "moons", "store", "route", "inventory", "buy","land", "exit" };
    std::vector<std::string> landingPhase = { "moons", "store","inventory", "buy","land", "exit", "send", "sell", "leave"};


    bool orbitPhase = true;

    std::string command = "";
    std::vector<std::string> arguments;
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
                    else if (command == "sell" && moonInGame =="corporation") {
                        moon.sellCargo(game,count);
                    }
                    else if (command == "send") {
                        count = stoi(arguments[0]);
                        moon.sendEmployees(game, count);
                    }
                    else if (command == "leave") {
                        moon.onDayBegin(game);
                        orbitPhase = true;
                        break;
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
