#include "AbstractMoon.h"

AbstractMoon::AbstractMoon()
{
}

AbstractMoon::~AbstractMoon()
{
}

/*
AbstractMoon::MoonWeather AbstractMoon::getRandomWeather()
{
    std::mt19937 myGenerator(std::random_device{}());
    std::discrete_distribution<> dist({ 25,25,25,25 });
    int index = dist(myGenerator);
    return static_cast<MoonWeather>(index);
}*/

const std::string& AbstractMoon::name() const
{
    // TODO: insert return statement here
    return moonName;
}




void AbstractMoon::onDayBegin(Game& g)
{

}
