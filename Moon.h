#ifndef MOON_H
#define MOON_H

#include "AbstractMoon.h"
#include <string>


class Moon : public AbstractMoon {
private:
    std::string name;
   
   

public:
    Moon(const std::string _name);
    std::string getName();
    void sellCargo(Game& g, int amount) override;
    void sendEmployees(Game& g, int amount) override;
};

#endif // !MOON_H
