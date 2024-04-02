#include "Moon.h"
#include "Game.h"

Moon::Moon()
{
}

Moon::Moon(const std::string _name, MoonWeather _moonWeather, float _minimumScrapValue, float _maxScrapValue, float _baseSurvivalChance)
{
    moonName = _name;
    moonWeather = _moonWeather;

}


std::string Moon::getName()
{
    return name;
}


//derived a getRandomWeather function in abstract class
MoonWeather Moon::getRandomWeather()
{
    //use mt19937 
    std::mt19937 myGenerator(std::random_device{}());
    //generate random int from lower bound to upper bound
    std::uniform_int_distribution<int> weatherDistribution(0, 3);
    int myRandomWeather = weatherDistribution(myGenerator);
    MoonWeather randomMoonWeather = static_cast<MoonWeather>(myRandomWeather);
    _moonWeather = randomMoonWeather;
    return _moonWeather;
}

void Moon::onDayBegin(Game& g)
{
    //std::cout << "You are here" << std::endl;
    //set new current day
    int day = g.showCurrentDay();
    day++;
    g.setCurrentDay(day);
 
    std::cout << "==============" << " DAY " << day << "====================" << std::endl;

    std::cout << "Current Cargo Value: $" << g.showCargo() << std::endl;
    std::cout << "Current Balance Value: $" << g.showBalance() << std::endl;
    std::cout << "Current quota: $" << g.showQuota() << "( " << 4 - g.showCurrentDay() << " days left to meet quota)" << std::endl;
    std::cout << "Current Moon Orbiting: " << g.getOrbitingMoon() << std::endl;

    std::cout << std::endl;

    std::cout << ">MOONS" << std::endl;
    std::cout << "To see the list of moons the autopilot can route to." << std::endl;


    std::cout << ">STORE" << std::endl;
    std::cout << "To see the company store's selection of useful items." << std::endl;


    std::cout << ">INVENTORY" << std::endl;
    std::cout << "To see the list of items you've already bought." << std::endl;
    std::cout << std::endl;
}


void Moon::sellCargo(Game& g, int amount)
{
}

void Moon::sendEmployees(Game& g, int amount)
{
    std::cout << "You send " << amount << " employees" << std::endl;
    std::cout << "You are here" << std::endl;
}
