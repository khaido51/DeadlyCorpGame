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
    //use this to store the generated weather at 1st.
    //clear it when leave the moon.
    std::map<std::string, MoonWeather> moonWeatherMap;

public:
    MoonManager();
    void createMoons();
    void registerMoon(AbstractMoon* moon);
    void showAllMoons();
    std::string lowerMoonName(AbstractMoon* moonName);
    const std::vector<AbstractMoon*>& getOrbitingMoon() const;
    void processCommands(const std::string& command, std::string& moonInGame, int& balance, std::vector<std::string> arguments, MoonWeather& weatherInMoon);
    AbstractMoon* findMoon(std::string moonInGame);

};

#endif // !MOONMANAGER_H
