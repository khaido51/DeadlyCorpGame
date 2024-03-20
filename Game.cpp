#include "Game.h"

const std::list<std::string> Game::commands = { "land", "leave", "exit" };

Game::Game()
{
}

//Constructor of creating a first game (cargo = 0; balance = 50, quota = 150, day = 1)
Game::Game(int _cargo, int _balance, int _currentDay, int _quota)
{
    cargo = _cargo;
    balance = _balance;
    currentDay = _currentDay;
    quota = _quota;
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

void Game::processCommand(const std::string& commands)
{
}
