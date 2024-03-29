#ifndef GAME_H
#define GAME_H

#include "ItemManager.h"
#include "MoonManager.h"
#include <iostream>
#include <string>
#include <list>


class Game {
private:
    int cargo;
    int balance;
    int currentDay;
    int quota;
    int numberOfEmployees;
    int maxCycleDay;
    ItemManager itemManager;
    MoonManager moonManager;
    static const std::list<std::string> commands;

   
 
    
public:
    Game();
    Game(int _cargo, int _balance, int _currentDay, int _quota, int numberOfEmployees, int _maxCycleDay);
    void initializeGame();
    void createItems(ItemManager &itemManager);
    void createMoons(MoonManager &moonManager);
    int showBalance();
    int showCargo();
    int showQuota();
    void processCommand(const std::string& commands, std::string moonInGame, std::string weatherInMoon);
};

#endif // !GAME_H
