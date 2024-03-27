#include "Game.h"

const std::list<std::string> Game::commands = { "land", "leave", "exit" };

Game::Game()
{
}

//Constructor of creating a first game (cargo = 0; balance = 50, quota = 150, day = 1)
Game::Game(int _cargo, int _balance, int _currentDay, int _quota, ItemManager _itemManager)
{
    cargo = _cargo;
    balance = _balance;
    currentDay = _currentDay;
    quota = _quota;
    itemManager = _itemManager;
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

void Game::processCommand(const std::string& commands, std::string moonInGame)
{
    std::cout << "WELCOME TO " << moonInGame <<std::endl;
    std::cout << "Current Cargo" << showCargo() << std::endl;
    std::cout << "Current Balance" << showBalance() << std::endl;
    
}
