#include "Game.h"



//Constructor of creating a first game (cargo = 0; balance = 50, currentDay = 1, quota = 150)
Game::Game(int _cargo, int _balance, int _currentDay, int _quota, int _numberOfEmployees, int _maxCycleDay, ItemManager& _itemManager, MoonManager& _moonManager)
    : cargo(_cargo), balance(_balance), currentDay(_currentDay), quota(_quota), numberOfEmployees(_numberOfEmployees), maxCycleDay(_maxCycleDay), itemManager(_itemManager), moonManager(_moonManager) 
{
    
}



void Game::initializeGame()
{
    std::string currentMoonOrbit = moonManager.getOrbitingMoon()[0]->name();
    std::cout << "Current Moon is " << currentMoonOrbit << std::endl;
    //Welcome screen
    std::cout << "    ___               _ _           ___                 \n" \
        "   /   \\___  __ _  __| | |_   _    / __\\___  _ __ _ __  \n" \
        "  / /\\ / _ \\/ _` |/ _` | | | | |  / /  / _ \\| '__| '_ \\ \n" \
        " / /_//  __/ (_| | (_| | | |_| | / /__| (_) | |  | |_) |\n" \
        "/___,' \\___|\\__,_|\\__,_|_|\\__, | \\____/\\___/|_|  | .__/ \n" \
        "                          |___/                  |_|    " << std::endl;
  

    std::cout << "Welcome!" << std::endl;
    std::cout << "We trust you will be a great asset to the corporation" << std::endl;
    std::cout << "==============" << " DAY " << currentDay << "====================" << std::endl;

    std::cout << "Current Cargo Value: $" << cargo << std::endl;
    std::cout << "Current Balance Value: $" << balance << std::endl;
    std::cout << "Current quota: $" << quota << "( " << maxCycleDay - currentDay << " days left to meet quota)" << std::endl;
    std::cout << "Current orbiting: "  << currentMoonOrbit << std::endl;

    std::cout << std::endl;

    std::cout << ">MOONS" << std::endl;
    std::cout << "To see the list of moons the autopilot can route to." << std::endl;


    std::cout << ">STORE" << std::endl;
    std::cout << "To see the company store's selection of useful items." << std::endl;


    std::cout << ">INVENTORY" << std::endl;
    std::cout << "To see the list of items you've already bought." << std::endl;
    std::cout << std::endl;

}


int Game::showBalance()
{
    return balance;
}

int Game::showCargo()
{
    return cargo;
}

int Game::showQuota()
{
    return quota;
}


ItemManager& Game::getItemManager() {
    return itemManager;
}

MoonManager& Game::getMoonManager() {
    return moonManager;
}


int Game::showCurrentDay()
{

    return currentDay;
}

void Game::setCurrentDay(int newDay)
{
    currentDay = newDay;
}

void Game::createMoons(MoonManager& moonManager)
{
    AbstractMoon* moon = new Moon("Corporation", MoonWeather::Clear,1,1,1);
    AbstractMoon* moon1 = new Moon("Prototyping", MoonWeather::Clear, 3, 30, 0.5);
    AbstractMoon* moon2 = new Moon("Insurance", MoonWeather::Clear, 5, 50, 0.45);
    AbstractMoon* moon3 = new Moon("Pledge", MoonWeather::Clear, 30, 50, 0.40);
    AbstractMoon* moon4 = new Moon("Defence", MoonWeather::Clear, 10, 70, 0.35);

    moonManager.registerMoon(moon);
    moonManager.registerMoon(moon1);
    moonManager.registerMoon(moon2);
    moonManager.registerMoon(moon3);
    moonManager.registerMoon(moon4);
}



void Game::createItems(ItemManager& itemManager)
{
    //Create new Item
    itemManager.registerItem(new Item("Flashlight", 60));
    itemManager.registerItem(new Item("Shovel", 100));
    itemManager.registerItem(new Item("Pro-flashlight", 200));
    itemManager.registerItem(new Item("Teleporter", 300));
    itemManager.registerItem(new Item("Inverse-Teleporter", 400));
    itemManager.registerItem(new Item("Backpack", 500));
    itemManager.registerItem(new Item("Hydraulics-Mk2", 1000));
}



void Game::processCommand(const std::string& commands, std::string moonInGame, MoonWeather weatherInMoon)
{
    if (moonInGame == "Corporation") {
        std::cout << "WELCOME TO " << moonInGame << std::endl;
        std::cout << std::endl;

        std::cout << "Current Cargo value: $" << cargo << std::endl;
        std::cout << "Current Balance value: $" << balance << std::endl;
        std::cout << "Current quota: $" << quota << std::endl;
        std::cout << "Number of employees: " << numberOfEmployees << std::endl;

        std::cout << std::endl;
        std::cout << "Type SELL to sell your cargo contents and increase your balance and achieve quota." << std::endl;
        std::cout << "Specify the amount to sell after the SELL word to only sell a portion of your cargo." << std::endl;
        std::cout << "Type LEAVE to leave the planet." << std::endl;
        std::cout << std::endl;


    }
    else {
        std::cout << std::endl;
        std::cout << "WELCOME TO " << moonInGame << std::endl;
        std::cout << std::endl;

        std::cout << "Current Cargo value: $" << cargo << std::endl;
        std::cout << "Current Balance value: $" << balance << std::endl;
        std::cout << "Current quota: $" << quota << std::endl;
        std::cout << "Number of employees: " << numberOfEmployees << std::endl;

        switch (weatherInMoon) {
        case MoonWeather::Clear:
            std::cout << "";
            //assign weatherInMoon
            break;
        case MoonWeather::Stormy:
            std::cout << "Proceed with caution as the moon is currently stormy";
            //assign weatherInMoon
            break;
        case MoonWeather::Flooded:
            std::cout << "Proceed with caution as the moon is currently stormy flooded";
            //assign weatherInMoon
            break;
        case MoonWeather::Eclipsed:
            std::cout << "Proceed with caution as the moon is currently stormy eclipsed";
            //assign weatherInMoon
            break;
        }
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Type SEND followed by the number of employees you wish to send inside the facility. All the other employees will stay on the ship." << std::endl;
        std::cout << "Type LEAVE to leave the planet." << std::endl;
        std::cout << std::endl;
      
    }
    
}



void Game::setOrbitingMoon(std::string moonInGame)
{
    orbitingMoon = moonInGame;
}

std::string Game::getOrbitingMoon()
{
    return orbitingMoon;
}





