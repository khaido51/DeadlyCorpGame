#ifndef MOON_H
#define MOON_H

#include "AbstractMoon.h"
#include <string>
#include <random>


class Moon : public AbstractMoon {
private:
    std::string name;

public:
    Moon(const std::string _name);
    std::string getName();
    MoonWeather getRandomWeather() override;
    void onDayBegin(Game& g) override;
    void sellCargo(Game& g, int amount) override;
    void sendEmployees(Game& g, int amount) override;
};

#endif // !MOON_H
