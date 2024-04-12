#ifndef GAME_H
#define GAME_H

#include "ItemManager.h"
#include "MoonManager.h"
#include <iostream>
#include <string>
#include <list>
#include <random>
#include <functional>


class Game {
private:
    int cargo = 0;
    int balance = 50;
    int currentDay = 1;
    int quota = 150;
    int numberOfEmployees = 4;
    std::string orbitingMoon = "";
    MoonWeather moonWeather;
    ItemManager itemManager;
    MoonManager moonManager;
    Moon moon;
    std::random_device rd;
    std::mt19937 rng;

  

public:
 
    Game();
    void initializeGame();
    void run(Game& g);
    int showBalance();
    int showCargo();
    int showQuota();
    int showCurrentDay();
    void newDay(Game& g);
    void setCargo(int newCargo);
    void setQuota(int newQuota);
    void setBalance(int newBalance);
    void setNumberOfEmployees(int num);
    int getNumberOfEmployees();
    void setCurrentDay(int newDay);
    std::mt19937& getRNG();
    int getRandomInt(int min, int max);
    float randomFloat();
    MoonWeather getRandomWeather();
    ItemManager getItemManager();
    MoonManager getMoonManager();  
    void processCommand(const std::string& commands, std::string moonInGame, MoonWeather weatherInMoon);
    std::string readCommand(const std::string& command);
    void setOrbitingMoon(std::string moonInGame);
    std::string getOrbitingMoon();
    void setMoonWeather(MoonWeather _moonWeather);
    MoonWeather getMoonWeather();
    int gameSimulation(int amount);
    void exitGame();

    
};

#endif // !GAME_H
