#ifndef GAME_H
#define GAME_H

#include "ItemManager.h"
#include "MoonManager.h"
#include <iostream>
#include <string>
#include <list>
#include <random>


class Game {
private:
    int cargo = 0;
    int balance = 500;
    int currentDay = 1;
    int quota = 150;
    int numberOfEmployees = 4;
    int maxCycleDay = 4;
    std::string orbitingMoon;
    std::string currentMoon;
    ItemManager itemManager;
    MoonManager moonManager;
    Moon moon;
    std::mt19937 rng;

  

public:
 
    //Game(int _cargo, int _balance, int _currentDay, int _quota, int numberOfEmployees, int _maxCycleDay, ItemManager& _itemManager, MoonManager& _moonManager);
    Game();
    void initializeGame();
    //void createItems();
    //void createMoons();
    //void createItems(ItemManager& itemManager);
    //void createMoons(MoonManager& moonManager);
    void run();
    int showBalance();
    int showCargo();
    int showQuota();
    int showCurrentDay();
    void setCurrentDay(int newDay);
    //void test();
    std::mt19937& getRNG();
    ItemManager getItemManager();
    MoonManager getMoonManager();  
    void processCommand(const std::string& commands, std::string moonInGame, MoonWeather weatherInMoon);
    void setOrbitingMoon(std::string moonInGame);
    std::string getOrbitingMoon();
    void gameSimulation(int amount);
    
};

#endif // !GAME_H
