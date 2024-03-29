#ifndef ABSTRACTMOON_H
#define ABSTRACTMOON_H
 
#include <iostream>
#include <string>
#include <random>
#include "util.h"

class Game;
enum class MoonWeather { Clear = 0, Flooded, Eclipsed, Stormy };

class AbstractMoon {
    
protected:
    std::string moonName;
    MoonWeather _moonWeather;
   
   
public:
    AbstractMoon();
    virtual ~AbstractMoon();
    const std::string& name() const;
    virtual MoonWeather getRandomWeather() = 0;
    virtual void onDayBegin(Game& g);
    virtual void sellCargo(Game& g, int amount) = 0;
    virtual void sendEmployees(Game& g, int amount) = 0;
};

#endif // !ABSTRACTMOON_H
