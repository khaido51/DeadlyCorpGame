#ifndef MOONMANAGER_H
#define MOONMANAGER_H

#include "AbstractMoon.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>

class MoonManager {
private:
    std::vector<AbstractMoon*> moons;
    static const std::list<std::string> commands;

public:
    MoonManager();
    void registerMoon(AbstractMoon* moon);
    void processCommands(const std::string& commands);
    void showAllMoons();
 

};

#endif // !MOONMANAGER_H
