#include "Game.h"

const std::list<std::string> Game::commands = { "land", "leave", "exit" };

Game::Game()
{
}

//Constructor of creating a first game (cargo = 0; balance = 50, quota = 150, day = 1)
Game::Game(int _cargo, int _balance, int _currentDay, int _quota, int _numberOfEmployees)
{
    cargo = _cargo;
    balance = _balance;
    currentDay = _currentDay;
    quota = _quota;
    numberOfEmployees = _numberOfEmployees;
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
    std::cout << std::endl;

    std::cout << "Current Cargo value: " << cargo << std::endl;
    std::cout << "Current Balance value: " << balance << std::endl;
    std::cout << "Number of employees quota: " << quota << std::endl;
    std::cout << "Proceed with caution as the moon is currently " << numberOfEmployees << std::endl;
    std::cout << std::endl;

    std::cout << "Type SEND followed by the number of employees you wish to send inside the facility. All the other employees will stay on the ship." << std::endl;
    std::cout << "Type LEave to leave the planet." << std::endl;
    std::cout << std::endl;

    

}
