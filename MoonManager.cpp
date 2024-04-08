#include "MoonManager.h"

std::vector<AbstractMoon*> moons;

MoonManager::MoonManager()
{
}

void MoonManager::createMoons()
{
	AbstractMoon* moon = new Moon("Corporation", MoonWeather::Clear, 1, 1, 1);
	AbstractMoon* moon1 = new Moon("Prototyping", MoonWeather::Clear, 3, 30, 0.5);
	AbstractMoon* moon2 = new Moon("Insurance", MoonWeather::Clear, 5, 50, 0.45);
	AbstractMoon* moon3 = new Moon("Pledge", MoonWeather::Clear, 30, 50, 0.40);
	AbstractMoon* moon4 = new Moon("Defence", MoonWeather::Clear, 10, 70, 0.35);

	registerMoon(moon);
	registerMoon(moon1);
	registerMoon(moon2);
	registerMoon(moon3);
	registerMoon(moon4);
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
		


std::string MoonManager::lowerMoonName(AbstractMoon* moonName)
{
	const std::string& name = moonName->name();
	std::string lowerCaseMoonName = name;
	util::lower(lowerCaseMoonName);
	return lowerCaseMoonName;
}

const std::vector<AbstractMoon*>& MoonManager::getOrbitingMoon() const
{
	return moons;
}

void MoonManager::processCommands(const std::string& command, std::string& moonInGame, int& balance, std::vector<std::string> arguments, MoonWeather& weatherInMoon)
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
			std::string moonName = lowerMoonName(moon);
			//lower the argumennts 
			util::lower(arguments[0]);
			util::lower(moonInGame);
			//checking moon name equals to arguments
			if (moonName == arguments[0])
			{
				//check if user already orbits that moon
				if (arguments[0] == moonInGame) {
					std::cout << "Already orbiting " << moonInGame << std::endl;
					return;
				}
				moonInGame = moon->name();
				std::cout << "Now orbiting to " << moonInGame << " Use Land command to land" << std::endl;
				std::cout << std::endl;
				foundMoon = true;
				
				weatherInMoon = moon->getMoonWeather();
				switch (weatherInMoon) {
				case MoonWeather::Clear:
					std::cout << "";
					break;
				case MoonWeather::Stormy:
					std::cout << "(Stormy)";
					break;
				case MoonWeather::Flooded:
					std::cout << "(Flooded)";
					break;
				case MoonWeather::Eclipsed:
					std::cout << "(Eclipsed)";
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

AbstractMoon* MoonManager::findMoon(std::string moonInGame) {
	for (AbstractMoon* moon : moons) {
		if (moonInGame == moon->name()) {
			return moon;
		}
	}
}




