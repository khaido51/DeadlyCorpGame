#include "MoonManager.h"

std::vector<AbstractMoon*> moons;

MoonManager::MoonManager()
{
}

void MoonManager::registerMoon(AbstractMoon* moon)
{
	moons.push_back(moon);
}

void MoonManager::showAllMoons()
{
	for (const auto& moon : moons) {
		std::cout << moon->name() << std::endl;
	}
}

void MoonManager::processCommands(const std::string& commands)
{
    std::cout << std::endl;
				std::cout << "Welcome to the exomoons catalogue" << std::endl;
				std::cout << "To route the autopilot to moon, use the word ROUTE" << std::endl;
				std::cout << "-------------------------------------------" << std::endl;

				
				showAllMoons();
				std::cout << std::endl;

}




