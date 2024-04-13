#ifndef MOON_H
#define MOON_H

#include "AbstractMoon.h"
#include <string>
#include <random>


class Moon : public AbstractMoon {
private:
    std::string name;
    MoonWeather moonWeather;
    float minimumScrapValue;
    float maxScrapValue;
    float baseSurvivalChance;
    

public:
    Moon();
    Moon(const std::string _name, MoonWeather _moonWeather, float _minimumScrapValue, float _maxScrapValue, float _baseSurvivalChance);
    std::string getName();
    MoonWeather getRandomWeather() override;
    void onDayBegin(Game& g) override;
    void sellCargo(Game& g, int amount) override;
    void sendEmployees(Game& g, int amount) override;
    float getMinimumScrapValue();
    float getMaxScrapValue();
    float getBaseSurvivalChance();
};

#endif // !MOON_H
