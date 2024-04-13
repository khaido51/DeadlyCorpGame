#include "Moon.h"
#include "Game.h"

Moon::Moon()
{
}

Moon::Moon(const std::string _name, MoonWeather _moonWeather, float _minimumScrapValue, float _maxScrapValue, float _baseSurvivalChance)
{
    moonName = _name;
    moonWeather = _moonWeather;
    minimumScrapValue = _minimumScrapValue;
    maxScrapValue = _maxScrapValue;
    baseSurvivalChance = _baseSurvivalChance;

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
    //set new current dayg

    std::cout << std::endl;
    std::cout << std::endl;
    int day = g.showCurrentDay();
    day++;
    g.setCurrentDay(day);
 
    std::cout << "==============" << " DAY " << day << "====================" << std::endl;

    std::cout << "Current Cargo Value: $" << g.showCargo() << std::endl;
    std::cout << "Current Balance Value: $" << g.showBalance() << std::endl;
    if (day % 4 == 0) {
        std::cout << "Current quota: $" << g.showQuota() << "( " << 0 << " day left to meet quota)" << std::endl;
    }
    else {
        std::cout << "Current quota: $" << g.showQuota() << "( " << 4 - (g.showCurrentDay() % 4) << " days left to meet quota)" << std::endl;
    }
    std::cout << "Current Moon Orbiting: " << g.getOrbitingMoon() << std::endl;


    std::cout << std::endl;

    std::cout << ">MOONS" << std::endl;
    std::cout << "To see the list of moons the autopilot can route to." << std::endl;


    std::cout << ">STORE" << std::endl;
    std::cout << "To see the company store's selection of useful items." << std::endl;


    std::cout << ">INVENTORY" << std::endl;
    std::cout << "To see the list of items you've already bought." << std::endl;
    std::cout << std::endl;

    if (day % 4 == 0) {
        std::cout << "NOTE: 0 days left to meet quota. Type route Corporation to go to the corp's moon and ell the scrap you collected for scrap." << std::endl;
    }
    else {

    }
   
}



void Moon::sellCargo(Game& g, int amount)
{
    int newCargo = 0;
    int newBalance = 0;

    newCargo = g.showCargo() - amount;
    newBalance = amount + g.showBalance();

    g.setCargo(newCargo);
    g.setBalance(newBalance);
   
    std::cout << "Your new balance is " << newBalance << std::endl;
    std::cout << "Your new Cargo is " << newCargo << std::endl;
    //g.showCargo();
    //g.showBalance();

}

void Moon::sendEmployees(Game& g, int amount)
{
    //std::cout << "You send " << amount << " employees" << std::endl;
    //std::cout << "You are here" << std::endl;
    g.gameSimulation(amount);
    //Simulation
    //numOfExplorer & numOfOperator


}

float Moon::getMinimumScrapValue()
{
    return minimumScrapValue;
}

float Moon::getMaxScrapValue()
{
    return maxScrapValue;
}

float Moon::getBaseSurvivalChance()
{
    return baseSurvivalChance;
}
