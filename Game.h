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
    int cargo;
    int balance;
    int currentDay;
    int quota;
    int numberOfEmployees;
    int maxCycleDay;
    std::string orbitingMoon = "";
    std::string currentMoon;
    ItemManager& itemManager;
    MoonManager& moonManager;
    std::mt19937 rng;
  

public:
 
    Game(int _cargo, int _balance, int _currentDay, int _quota, int numberOfEmployees, int _maxCycleDay, ItemManager& _itemManager, MoonManager& _moonManager);
    void initializeGame(std::string& moonInGame);
    void createItems(ItemManager& itemManager);
    void createMoons(MoonManager& moonManager);
    
    int showBalance();
    int showCargo();
    int showQuota();
    int showCurrentDay();
    void setCurrentDay(int newDay);
    std::mt19937& getRNG();
    ItemManager& getItemManager();
    MoonManager& getMoonManager();  
    void processCommand(const std::string& commands, std::string moonInGame, MoonWeather weatherInMoon);
    void setOrbitingMoon(std::string moonInGame);
    std::string getOrbitingMoon();
    void gameSimulation(int amount);
    void findMoon(std::string moonInGame);
};

#endif // !GAME_H
