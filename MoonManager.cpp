#include "MoonManager.h"

std::vector<AbstractMoon*> moons;

MoonManager::MoonManager()
{
}

void MoonManager::registerMoon(AbstractMoon* moon)
{
	moons.push_back(moon);
}

void MoonManager::showAllMoons(std::string& weatherInMoon)
{
	weatherInMoon.clear();

	for (const auto& moon : moons) {
		std::cout << "* " << moon->name() << " ";

		//Get the weather for current moon
		MoonWeather moonWeather = moon->getRandomWeather();

		switch (moonWeather) {
		case MoonWeather::Clear:
			std::cout << "";
			//assign weatherInMoon
			weatherInMoon = "Clear";
			break;
		case MoonWeather::Stormy:
			std::cout << "(Stormy)";
			//assign weatherInMoon
			weatherInMoon = "Stormy";
			break;
		case MoonWeather::Flooded:
			std::cout << "(Flooded)";
			//assign weatherInMoon
			weatherInMoon = "Flooded";
			break;
		case MoonWeather::Eclipsed:
			std::cout << "(Eclipsed)";
			//assign weatherInMoon
			weatherInMoon = "Eclipsed";
			break;
		}
			std::cout << std::endl;
	}

	
}

void MoonManager::processCommands(const std::string& command, bool& orbitingPhase, std::string& moonInGame, int& balance, std::vector<std::string> arguments, std::string& weatherInMoon)
{
	if (weatherInMoon.empty()) {
		weatherInMoon = "Unknown"; // or any other default value
	}

	if (command == "moons") {
		std::cout << std::endl;
		std::cout << "Welcome to the exomoons catalogue" << std::endl;
		std::cout << "To route the autopilot to moon, use the word ROUTE" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;

		showAllMoons(weatherInMoon);
		std::cout << std::endl;
		std::cout << "Current weather: " << weatherInMoon << std::endl;
	}
	if (command == "route") {
		bool foundMoon = false;
		for (const auto& moon : moons) {
			//converting moon to lower case
			const std::string& moonName = moon->name();
			std::string lowerCaseMoonName = moonName;
			util::lower(lowerCaseMoonName);
			
			//checking moon name equals to arguments
			if (lowerCaseMoonName == arguments[0]) {
				std::cout << "Now orbiting to " << moon->name() << " Use Land command to land" << std::endl;
				std::cout << std::endl;
				foundMoon = true;
				moonInGame = moon->name();
				std::cout << weatherInMoon << std::endl;
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




