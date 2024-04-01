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
		std::cout << "* " << moon->name() << " ";

		//Get the weather for current moon

		switch (moon->getRandomWeather()) {
		case MoonWeather::Clear:
			std::cout << "";
			//assign weatherInMoon
			
			break;
		case MoonWeather::Stormy:
			std::cout << "(Stormy)";
			//assign weatherInMoon
			
			break;
		case MoonWeather::Flooded:
			std::cout << "(Flooded)";
			//assign weatherInMoon
			
			break;
		case MoonWeather::Eclipsed:
			std::cout << "(Eclipsed)";
			//assign weatherInMoon
			
			break;
		}
		std::cout << std::endl;
	}


}

void MoonManager::processCommands(const std::string& command, bool& orbitingPhase, std::string& moonInGame, int& balance, std::vector<std::string> arguments)
{
	

	if (command == "moons") {
		std::cout << std::endl;
		std::cout << "Welcome to the exomoons catalogue" << std::endl;
		std::cout << "To route the autopilot to moon, use the word ROUTE" << std::endl;
		std::cout << "-------------------------------------------" << std::endl;

		showAllMoons();
		std::cout << std::endl;
		
	}
	if (command == "route") {
		bool foundMoon = false;
		for (const auto& moon : moons) {
			//converting moon to lower case
			const std::string& moonName = moon->name();
			std::string lowerCaseMoonName = moonName;
			util::lower(lowerCaseMoonName);
			util::lower(arguments[0]);

			//checking moon name equals to arguments
			if (lowerCaseMoonName == arguments[0]) {
				std::cout << "Now orbiting to " << moon->name() << " Use Land command to land" << std::endl;
				std::cout << std::endl;
				foundMoon = true;
				moonInGame = moon->name();
				
				switch (moon->getMoonWeather()) {
				case MoonWeather::Clear:
					std::cout << "";
					//assign weatherInMoon
					break;
				case MoonWeather::Stormy:
					std::cout << "(Stormy)";
					//assign weatherInMoon
					break;
				case MoonWeather::Flooded:
					std::cout << "(Flooded)";
					//assign weatherInMoon
					break;
				case MoonWeather::Eclipsed:
					std::cout << "(Eclipsed)";
					//assign weatherInMoon

					break;
				}
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




