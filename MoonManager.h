#ifndef MOONMANAGER_H
#define MOONMANAGER_H


#include "Moon.h"
#include "util.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>

class MoonManager {
public:
    std::vector<AbstractMoon*> moons;
    std::vector<std::string> arguments;
    static const std::list<std::string> commands;

public:
    MoonManager();
    void registerMoon(AbstractMoon* moon);
    void showAllMoons();
    const std::vector<AbstractMoon*>& getOrbitingMoon() const;
    void processCommands(const std::string& command, std::string& moonInGame, int& balance, std::vector<std::string> arguments, MoonWeather& weatherInMoon);


};

#endif // !MOONMANAGER_H
