#include "MoonManager.h"

std::vector<AbstractMoon*> moons;

MoonManager::MoonManager()
{
}

void MoonManager::registerMoon(AbstractMoon* moon)
{
	moons.push_back(moon);
}

void MoonManager::showAllMoons(std::string weatherInMoon)
{
	for (const auto& moon : moons) {
		std::cout << "* " << moon->name() << " ";
		switch (moon->getRandomWeather()) {
		case MoonWeather::Clear:
			std::cout << "";
			weatherInMoon = "Clear";
			return ;
			break;
		case MoonWeather::Stormy:
			std::cout << "(Stormy)";
			weatherInMoon = "Stormy";
			break;
		case MoonWeather::Flooded:
			std::cout << "(Flooded)";
			weatherInMoon = "Flooded";
			break;
		case MoonWeather::Eclipsed:
			std::cout << "(Eclipsed)";
			weatherInMoon = "Eclipsed";
			break;
		}
			std::cout << std::endl;
	}

	
}

void MoonManager::processCommands(const std::string& command, bool& orbitingPhase, std::string& moonInGame, int& balance, std::vector<std::string> arguments, std::string weatherInMoon)
{
	if (command == "moons") {
		std::cout << std::endl;
		std::cout << "Welcome to the exomoons catalogue" << std::endl;
		std::cout << "To route the autopilot to moon, use the word ROUTE" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;

		showAllMoons(weatherInMoon);
		std::cout << std::endl;
	}
	if (command == "route") {
		bool foundMoon = false;
		for (const auto& moon : moons) {
			if (moon->name() == arguments[0]) {
				std::cout << "Now orbiting to " << moon->name() << " Use Land command to land" << std::endl;
				std::cout << std::endl;
				foundMoon = true;
				moonInGame = moon->name();
				
				std::cout << "Balance: $" << balance << std::endl;
				std::cout << std::endl;
				break;
			}

		}
		if (!foundMoon) {
			std::cout << "Incorrect moon" << std::endl;
		}
	}
	
}




