#ifndef MOONMANAGER_H
#define MOONMANAGER_H

#include "AbstractMoon.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>

class MoonManager : public AbstractMoon {
private:
    std::vector<AbstractMoon*> moons;
    static const std::list<std::string> commands;

public:
    MoonManager();
    void registerMoon(AbstractMoon* moon);
    void processCommands(const std::string& commands);
    void sellCargo(Game& g, int amount) override;
    void sendEmployees(Game& g, int amount) override;

};

#endif // !MOONMANAGER_H
