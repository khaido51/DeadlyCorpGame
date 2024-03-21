// DeadlyCorpGame.cpp : Defines the entry point for the application.
//

#include "DeadlyCorpGame.h"
#include "Game.h"
#include "MoonManager.h"
#include "AbstractMoon.h"
#include "ItemManager.h"
#include <iostream>
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
    //std::list<string> commands = { "moons", "store", "inventory" };

    Game game(cargo, balance, day, quota);
    MoonManager moonManager;
    ItemManager itemManager;

    //Create new Item
    itemManager.registerItem(new Item("Flashlight", 60));
    itemManager.registerItem(new Item("Shovel", 100));
    itemManager.registerItem(new Item("Pro-flashlight", 200));
    itemManager.registerItem(new Item("Teleporter", 300));
    itemManager.registerItem(new Item("Inverse-Teleporter", 400));
    itemManager.registerItem(new Item("Backpack", 500));
    itemManager.registerItem(new Item("Hydraulics Mk2", 1000));


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
            moonManager.processCommands(command);
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
