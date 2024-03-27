// DeadlyCorpGame.cpp : Defines the entry point for the application.
//

#include "DeadlyCorpGame.h"
#include "Game.h"
#include "Moon.h"
#include "MoonManager.h"
#include "Game.h"
#include "AbstractMoon.h"
#include "ItemManager.h"
#include <iostream>
#include <map>
#include <string>
#include <list>

using namespace std; 
int main()
{
    //Initialize to default value for each variable when the game start
    int day = 1;
    int balance = 500;
    int cargo = 0;
    int quota = 150;
    int maxDayCycle = 4;
    bool orbitingPhase = false;
    std::string moonInGame = "";
    std:string moons[5] = { "Corporation", "Prototyping", "Insurance", "Pledge", "Defence" };
    ItemManager itemManager;

    //std::list<string> commands = { "moons", "store", "inventory" };

    //Create new Item
    itemManager.registerItem(new Item("Flashlight", 60));
    itemManager.registerItem(new Item("Shovel", 100));
    itemManager.registerItem(new Item("Pro-flashlight", 200));
    itemManager.registerItem(new Item("Teleporter", 300));
    itemManager.registerItem(new Item("Inverse-Teleporter", 400));
    itemManager.registerItem(new Item("Backpack", 500));
    itemManager.registerItem(new Item("Hydraulics Mk2", 1000));

    Game game(cargo, balance, day, quota, itemManager);
    MoonManager moonManager;
    
    
   
    AbstractMoon* moon = new Moon("Corporation");
    AbstractMoon* moon1 = new Moon("Prototyping");
    AbstractMoon* moon2 = new Moon("Insurance");
    AbstractMoon* moon3 = new Moon("Pledge");
    AbstractMoon* moon4 = new Moon("Defence");

    
    /*
    //Set random weather for each moon
    std::mt19937 myGenerator(std::random_device{}());
    std::discrete_distribution<> dist({ 25, 25, 25, 25 });
     */
    moonManager.registerMoon(moon);
    moonManager.registerMoon(moon1);
    moonManager.registerMoon(moon2);
    moonManager.registerMoon(moon3);
    moonManager.registerMoon(moon4);
 
   
    


    //Welcome screen
    std::cout << "    ___               _ _           ___                 \n" \
        "   /   \\___  __ _  __| | |_   _    / __\\___  _ __ _ __  \n" \
        "  / /\\ / _ \\/ _` |/ _` | | | | |  / /  / _ \\| '__| '_ \\ \n" \
        " / /_//  __/ (_| | (_| | | |_| | / /__| (_) | |  | |_) |\n" \
        "/___,' \\___|\\__,_|\\__,_|_|\\__, | \\____/\\___/|_|  | .__/ \n" \
        "                          |___/                  |_|    " << std::endl;

    std::cout << "Welcome!" << std::endl;
    std::cout << "We trust you will be a great asset to the corporation" << std::endl;
    std::cout << "==============" << " DAY " << day << "====================" << std::endl;

    std::cout << "Current Cargo Value: $" << game.showCargo() << std::endl;
    std::cout << "Current Balance Value: $" << game.showBalance() << std::endl;
    std::cout << "Current quota: $" << game.showQuota() << "( " << maxDayCycle - day << " days left to meet qo" << std::endl;

    std::cout << std::endl;

    std::cout << "Test" << std::endl;
    std::cout << ">MOONS" << std::endl;
    std::cout << "To see the list of moons the autopilot can route to." << std::endl;


    std::cout << ">STORE" << std::endl;
    std::cout << "To see the company store's selection of useful items." << std::endl;

    
    std::cout << ">INVENTORY" << std::endl;
    std::cout << "To see the list of items you've already bought." << std::endl;

    
    //If cases
    std::string command = "";
    int error = 0;
    while (true) {
        std::cin >> command;
        if (command == "moons") {
            int i; int j;
            moonManager.processCommands(command, orbitingPhase, moonInGame);
            if (orbitingPhase = true) {
                std::cin >> command;
                if (command == "land") {
                    std::cout << "Now change to landing phase" << std::endl;
                    std::cout << moonInGame  << std::endl;
                    game.processCommand(command, moonInGame);


                }
            }
           
        }
        else if (command == "store") {
            itemManager.processCommand(command, balance);
        }
        else if (command == "inventory") {
            itemManager.processCommand(command, balance);
        }
        else {
            std::cout << "Invalid Command" << std::endl;
        }

        
    }

	return 0;

}
