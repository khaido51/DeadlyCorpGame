#ifndef GAME_H
#define GAME_H

#include "ItemManager.h"
#include <iostream>
#include <string>
#include <list>

class Game {
private:
    int cargo;
    int balance;
    int currentDay;
    int quota;
    ItemManager* itemManager;
    static const std::list<std::string> commands;
    
public:
    Game();
    Game(int _cargo, int _balance, int _currentDay, int _quota);
    int showBalance();
    int showCargo();
    int showQuota();
    void processCommand(const std::string& commands);
};

#endif // !GAME_H
