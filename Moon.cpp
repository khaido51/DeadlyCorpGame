#include "Moon.h"

Moon::Moon(const std::string _name)
{
    moonName = _name;
  
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
    return randomMoonWeather;
}

void Moon::onDayBegin(Game& g)
{
}


void Moon::sellCargo(Game& g, int amount)
{
}

void Moon::sendEmployees(Game& g, int amount)
{

}
