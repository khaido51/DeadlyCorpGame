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

std::string MoonManager::convertWeatherToString(MoonWeather weather)
{
	switch (weather) {
	case MoonWeather::Clear:
		return "";
		break;

	case MoonWeather::Stormy:
		return "(Stormy)";
		break;

	case MoonWeather::Flooded:
		return "(Flooded)";
		break;

	case MoonWeather::Eclipsed:
		return "(Eclipsed)";
		break;
	}
}

void MoonManager::showAllMoons()
{
	for (const auto& moon : moons) {
		std::cout << "* " << moon->name() << " ";

		//Get the weather for current moon
		MoonWeather weather;
		if (moon->name() == "Corporation") {
			weather = MoonWeather::Clear;
			std::cout << "";
		}
		else {
			weather = moon->getRandomWeather();
		}
		std::string weatherString = convertWeatherToString(weather);
		std::cout << weatherString;
		
		//add each key value pair into the map (moonName as key, weather is value)
		moonWeatherMap.insert(std::pair<std::string, MoonWeather>(moon->name(), weather));
		std::cout << std::endl;
	}
}

void MoonManager::showAllMoonsFromMap()
{
	for(const auto & keyValue : moonWeatherMap) {
		std::string key = keyValue.first;
		std::cout << "* " << key << " ";
		MoonWeather value = keyValue.second;
		
		std::string weatherString = convertWeatherToString(value);
		std::cout << weatherString;
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

		if (moonWeatherMap.empty()) {
			showAllMoons();
		}
		else {
			showAllMoonsFromMap();
		}
		
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
				//storing moon.name() to moonInGame to get display after land command
				moonInGame = moon->name();
				std::cout << "Now orbiting to " << moonInGame << " Use Land command to land" << std::endl;
				std::cout << std::endl;
				foundMoon = true;
				
				weatherInMoon = moon->getMoonWeather();
			
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

MoonManager::~MoonManager()
{
	for (AbstractMoon* moon : moons) {
		delete moon;
	}

	moons.clear();


}


