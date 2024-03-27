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
		std::cout << moon->name()  << std::endl;
	}

	
}

void MoonManager::processCommands(const std::string& commands, bool& orbitingPhase, std::string& moonInGame)
{
    std::cout << std::endl;
	std::cout << "Welcome to the exomoons catalogue" << std::endl;
	std::cout << "To route the autopilot to moon, use the word ROUTE" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;

				
	showAllMoons();
	std::cout << std::endl;

    while (true) {
        //after command store now they can use Buy command
        std::string moonManagerCommand = " ";
        std::getline(std::cin >> std::ws, moonManagerCommand);
        util::splitArguments(moonManagerCommand, arguments);
		
		if (moonManagerCommand == "route") {
			bool foundMoon = false;
			for (const auto& moon : moons) {
				if (moon->name() == arguments[0]) {
					std::cout << "Now orbiting to " << moon->name() << " Use Land command to land" << std::endl;
					foundMoon = true;
					moonInGame = moon->name();
					
				}
			}
			if (!foundMoon) {
				std::cout << "Incorrect moon" << std::endl;
			}
			break;
		}
		else {
			std::cout << "Invalid Command " << std::endl;
			
		}

    }

}




