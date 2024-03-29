#ifndef MOONMANAGER_H
#define MOONMANAGER_H

#include "AbstractMoon.h"
#include "Moon.h"
#include "util.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

class MoonManager {
private:
    std::vector<AbstractMoon*> moons;
    std::vector<std::string> arguments;
    static const std::list<std::string> commands;

public:
    MoonManager();
    void registerMoon(AbstractMoon* moon);
    void processCommands(const std::string& command, bool& orbitingPhase, std::string& moonInGame, int& balance, std::vector<std::string> arguments, std::string weatherInMoon);
    void showAllMoons(std::string weatherInMoon);
 

};

#endif // !MOONMANAGER_H
