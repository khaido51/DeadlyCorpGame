#include "Game.h"



//Constructor of creating a first game (cargo = 0; balance = 50, currentDay = 1, quota = 150)
/*
Game::Game(int _cargo, int _balance, int _currentDay, int _quota, int _numberOfEmployees, int _maxCycleDay, ItemManager& _itemManager, MoonManager& _moonManager)
    : cargo(_cargo), balance(_balance), currentDay(_currentDay), quota(_quota), numberOfEmployees(_numberOfEmployees), maxCycleDay(_maxCycleDay), itemManager(_itemManager), moonManager(_moonManager) 
{
    
}
*/
Game::Game() : itemManager(), moonManager() {}


/*
Game::Game(ItemManager, MoonManager)
{
}
*/
void Game::initializeGame()
{
    itemManager.createItems();
    moonManager.createMoons();

    orbitingMoon = moonManager.getOrbitingMoon()[0]->name();
    std::cout << "Current Moon is " << orbitingMoon << std::endl;
    //Welcome screen
    std::cout << "    ___               _ _           ___                 \n" \
        "   /   \\___  __ _  __| | |_   _    / __\\___  _ __ _ __  \n" \
        "  / /\\ / _ \\/ _` |/ _` | | | | |  / /  / _ \\| '__| '_ \\ \n" \
        " / /_//  __/ (_| | (_| | | |_| | / /__| (_) | |  | |_) |\n" \
        "/___,' \\___|\\__,_|\\__,_|_|\\__, | \\____/\\___/|_|  | .__/ \n" \
        "                          |___/                  |_|    " << std::endl;
  

    std::cout << "Welcome!" << std::endl;
    std::cout << "We trust you will be a great asset to the corporation" << std::endl;

    
    std::cout << "==============" << " DAY " << currentDay << "====================" << std::endl;

    std::cout << "Current Cargo Value: $" << cargo << std::endl;
    std::cout << "Current Balance Value: $" << balance << std::endl;
    std::cout << "Current quota: $" << quota << "( " << maxCycleDay - currentDay << " days left to meet quota)" << std::endl;
    std::cout << "Current orbiting: "  << orbitingMoon << std::endl;

    std::cout << std::endl;

    std::cout << ">MOONS" << std::endl;
    std::cout << "To see the list of moons the autopilot can route to." << std::endl;


    std::cout << ">STORE" << std::endl;
    std::cout << "To see the company store's selection of useful items." << std::endl;


    std::cout << ">INVENTORY" << std::endl;
    std::cout << "To see the list of items you've already bought." << std::endl;
    std::cout << std::endl;

    

}


int Game::showBalance()
{
    return balance;
}

int Game::showCargo()
{
    return cargo;
}

int Game::showQuota()
{
    return quota;
}


ItemManager Game::getItemManager() {
    return itemManager;
}

MoonManager Game::getMoonManager() {
    return moonManager;
}


int Game::showCurrentDay()
{

    return currentDay;
}

void Game::setCurrentDay(int newDay)
{
    currentDay = newDay;
}


/*
void Game::createMoons(MoonManager& moonManager)
{
    AbstractMoon* moon = new Moon("Corporation", MoonWeather::Clear,1,1,1);
    AbstractMoon* moon1 = new Moon("Prototyping", MoonWeather::Clear, 3, 30, 0.5);
    AbstractMoon* moon2 = new Moon("Insurance", MoonWeather::Clear, 5, 50, 0.45);
    AbstractMoon* moon3 = new Moon("Pledge", MoonWeather::Clear, 30, 50, 0.40);
    AbstractMoon* moon4 = new Moon("Defence", MoonWeather::Clear, 10, 70, 0.35);

    moonManager.registerMoon(moon);
    moonManager.registerMoon(moon1);
    moonManager.registerMoon(moon2);
    moonManager.registerMoon(moon3);
    moonManager.registerMoon(moon4);
}

void Game::createMoons() {
    moonManager.createMoons();
}

void Game::createItems(){
    itemManager.createItems();
}
*/
/*
void Game::createItems(ItemManager& itemManager)
{
    //Create new Item
    itemManager.registerItem(new Item("Flashlight", 60, 1, 1.05, 1, 0, 1));
    itemManager.registerItem(new Item("Shovel", 100, 1, 1.05, 1, 0, 1));
    itemManager.registerItem(new Item("Pro-flashlight", 200, 1, 1.1, 1, 0, 1));
    itemManager.registerItem(new Item("Teleporter", 300, 1, 1, 1, 0.33, 1));
    itemManager.registerItem(new Item("Inverse-Teleporter", 400, 1.1, 0.8, 1, 0, 1));
    itemManager.registerItem(new Item("Backpack", 500, 1, 1, 1, 0, 1.25));
    itemManager.registerItem(new Item("Hydraulics-Mk2", 1000, 1, 1, 1.25, 1, 1));
}
*/


void Game::processCommand(const std::string& commands, std::string moonInGame, MoonWeather weatherInMoon)
{
    if (moonInGame == "Corporation") {
        std::cout << "WELCOME TO " << moonInGame << std::endl;
        std::cout << std::endl;

        std::cout << "Current Cargo value: $" << cargo << std::endl;
        std::cout << "Current Balance value: $" << balance << std::endl;
        std::cout << "Current quota: $" << quota << std::endl;
        std::cout << "Number of employees: " << numberOfEmployees << std::endl;

        std::cout << std::endl;
        std::cout << "Type SELL to sell your cargo contents and increase your balance and achieve quota." << std::endl;
        std::cout << "Specify the amount to sell after the SELL word to only sell a portion of your cargo." << std::endl;
        std::cout << "Type LEAVE to leave the planet." << std::endl;
        std::cout << std::endl;


    }
    else {
        std::cout << std::endl;
        std::cout << "WELCOME TO " << moonInGame << std::endl;
        std::cout << std::endl;

        std::cout << "Current Cargo value: $" << cargo << std::endl;
        std::cout << "Current Balance value: $" << balance << std::endl;
        std::cout << "Current quota: $" << quota << std::endl;
        std::cout << "Number of employees: " << numberOfEmployees << std::endl;

        switch (weatherInMoon) {
        case MoonWeather::Clear:
            std::cout << "";
            //assign weatherInMoon
            break;
        case MoonWeather::Stormy:
            std::cout << "Proceed with caution as the moon is currently stormy";
            //assign weatherInMoon
            break;
        case MoonWeather::Flooded:
            std::cout << "Proceed with caution as the moon is currently stormy flooded";
            //assign weatherInMoon
            break;
        case MoonWeather::Eclipsed:
            std::cout << "Proceed with caution as the moon is currently stormy eclipsed";
            //assign weatherInMoon
            break;
        }
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Type SEND followed by the number of employees you wish to send inside the facility. All the other employees will stay on the ship." << std::endl;
        std::cout << "Type LEAVE to leave the planet." << std::endl;
        std::cout << std::endl;
      
    }
    
}



std::mt19937& Game::getRNG() {

    return rng;
}

int Game::getRandomInt(int min, int max)
{
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}



void Game::setOrbitingMoon(std::string moonInGame)
{
    
    orbitingMoon = moonInGame;
    //std::cout << "Orbiting moon set to: " << orbitingMoon << std::endl;
    
}

std::string Game::getOrbitingMoon()
{
    //std::cout << "Returning orbiting moon: " << orbitingMoon << std::endl;
    return orbitingMoon;
}

void Game::setMoonWeather(MoonWeather _moonWeather)
{
    moonWeather = _moonWeather;
}

MoonWeather Game::getMoonWeather()
{
    return moonWeather;
}


void Game::gameSimulation(int amount) {
    //numOfOperator = aliveEmployees - numExplorers
    //explorerSurvivalChance = explorerBaseSurvivalChance * explorerSurvivalChanceMultiplier
    //operatorSurvivalChance = 1.0 * operatorSurvivalChanceMultiplier
    int numOfExplorer = amount;
    int numOfOperator = 4 - amount;
    float exploreBaseSurvivalChance = 0.0;
    float explorerSurvivalChanceMultiplier;
    float explorerSurvivalChance = 1;
    float scrapValueMultiplier = 1;

    std::string moonName = getOrbitingMoon();
    MoonWeather moonWeather = getMoonWeather();

    //float weatherScrapValueMultiplier = 1;
    //float weatherExplorerSurvivalChanceMultiplier = 1;
    float weatherOperatorSurvivalChanceMultiplier = 1;

    switch (moonWeather) {
    case MoonWeather::Clear:
        scrapValueMultiplier *= 1;
        explorerSurvivalChance *= 1;
        weatherOperatorSurvivalChanceMultiplier = 1;
        std::cout << "";
        break;
    case MoonWeather::Stormy:
        scrapValueMultiplier *= 0.75;
        explorerSurvivalChance *= 1;
        weatherOperatorSurvivalChanceMultiplier = 1;
        std::cout << "(Stormy)";
        break;
    case MoonWeather::Flooded:
        scrapValueMultiplier *= 1;
        explorerSurvivalChance *= 0.7;
        weatherOperatorSurvivalChanceMultiplier = 1;
        std::cout << "(Flooded)";
        break;
    case MoonWeather::Eclipsed:
        scrapValueMultiplier *= 1;
        explorerSurvivalChance *= 0.9;
        weatherOperatorSurvivalChanceMultiplier = 0.7;
        std::cout << "(Eclipsed)";
        break;
    }

    Moon moon;
    AbstractMoon* abPtr = moonManager.findMoon(moonName);
    Moon* moonPtr = static_cast<Moon*>(abPtr);
    moonPtr->getBaseSurvivalChance();


    //get base survival chance
    if (abPtr->name() == getOrbitingMoon()) {
        exploreBaseSurvivalChance = moonPtr->getBaseSurvivalChance();
        explorerSurvivalChance = explorerSurvivalChance * exploreBaseSurvivalChance;
    }
    std::cout << explorerSurvivalChance << std::endl;


    //loop inventory to get item
    //single item

    std::set<Item*> inventory = itemManager.getInventory();
    for (auto item : inventory) {
        explorerSurvivalChanceMultiplier = item->getExplorerSurvivalChanceMultiplier();
        scrapValueMultiplier *= item->getScrapValueMultiplier();
        explorerSurvivalChance *= explorerSurvivalChanceMultiplier;
        getRNG();
    }


    //calculate revenue
    
    /*
    std::vector<Item*> items;
    Item* item;
    for (auto item : items) {
        item = itemManager.findItemInInventory();
        items.push_back(item);

    }
   
    for (auto item : items) {
        explorerSurvivalChanceMultiplier = item->getExplorerSurvivalChanceMultiplier();
        explorerSurvivalChance *= explorerSurvivalChanceMultiplier;
    }
    //explorerSurvivalChanceMultiplier = item->getExplorerSurvivalChanceMultiplier();
    //std::cout << explorerSurvivalChanceMultiplier << std::endl;
   */
    //explorerSurvivalChance = explorerSurvivalChance * weatherExplorerSurvivalChanceMultiplier;
    std::cout << explorerSurvivalChance << std::endl;
    std::cout << "scrapValueMultiplier: " << scrapValueMultiplier << std::endl;

    int revenue = getRandomInt(moonPtr->getMinimumScrapValue() * int(scrapValueMultiplier), moonPtr->getMaxScrapValue() * int(scrapValueMultiplier));
    std::cout <<  revenue << std::endl;

    //totalRevenue = 0 
    //deadExplorers = 0 
    //REPEAT numExplorers TIMES: 
    //  revenue = randomIntBetween(minScrapValue * scrapValueMultplier, maxScrapValue * scrapValueMultplier)
    

    //IF randomFloat01() < explorerSurvivalChance: 
        //This employee made it out alive 
        //  totalRevenue = totalRevenue + revenue
    //ELSE randomFloat01() >= explorerSaveChance: 
    //This employee died and was NOT saved 
    //    totalRevenue = totalRevenue + revenue * lootRecoveryMultiplier 
    //    deadExplorers = deadExplorers + 1
}


std::string Game::readCommand(const std::string& command)
{
    std::cout << ">";
    std::string userInput;
    std::getline(std::cin >> std::ws, userInput);
    return userInput;
}
    



void Game::run(Game& g) {
    
    //list of command in orbiting phase
    std::vector<std::string> orbitingPhase = { "moons", "store", "route", "inventory", "buy","land", "exit" };
    //list of command in landing phase
    std::vector<std::string> landingPhase = { "moons", "store","inventory", "buy","land", "exit", "send", "sell", "leave", "route" };
    //arguments store the second word of user input
    std::vector<std::string> arguments;

    //flag
    bool orbitPhase = true;
    bool foundPhase = false;
    //number of employees player wants to send.
    int count = 0;

    std::string command = "";
    while (true) {
        //read user's input
        command = readCommand(command);
        //Split the command
        util::splitArguments(command, arguments);
        //change to lower case
        util::lower(command);

        //check for orbiting phase
        if (orbitPhase == true) {
            //loop through orbitingPhase
            for (auto phase : orbitingPhase) {
                if (command == phase) {
                    foundPhase = true;
                    if (command == "moons") {
                        //passing the command, orbiting moon , balance, argument[0] and weather of the moon.
                        moonManager.processCommands(command, orbitingMoon, balance, arguments, moonWeather);
                    }
                    else if (command == "store") {
                        itemManager.processCommand(command, balance, arguments, cargo, quota);
                    }
                    else if (command == "inventory") {
                        itemManager.processCommand(command, balance, arguments, cargo, quota);
                    }
                    else if (command == "route") {
                        moonManager.processCommands(command, orbitingMoon, balance, arguments, moonWeather);
                    }
                    else if (command == "buy") {
                        itemManager.processCommand(command, balance, arguments, cargo, quota);
                    }
                    else if (command == "land") {
                        processCommand(command, orbitingMoon, moonWeather);
                        setOrbitingMoon(orbitingMoon);
                        setMoonWeather(moonWeather);
                        //std::cout << "You are orbiting to " << getOrbitingMoon() << std::endl;
                        orbitPhase = false;
                        break;
                    }
                }
            }
        }
  
        else if (orbitPhase == false) {
            for (auto phase : landingPhase) {
                if (command == phase) {
                    foundPhase = true;

                    if (command == "moons") {
                        moonManager.processCommands(command, orbitingMoon, balance, arguments, moonWeather);
                    }
                    else if (command == "store") {
                        itemManager.processCommand(command, balance, arguments, cargo, quota);
                    }
                    else if (command == "inventory") {
                        itemManager.processCommand(command, balance, arguments, cargo, quota);
                    }
                    else if (command == "buy") {
                        itemManager.processCommand(command, balance, arguments, cargo, quota);
                    }
                    
                    else if (command == "sell") {
                        if (orbitingMoon != "corporation") {
                            std::cout << "You can not use sell command in this moon " << std::endl;
                        }
                        else {
                            moon.sellCargo(g, count);
                        }
                    }
                    else if (command == "send") {
                        if (orbitingMoon == "corporation") {
                            std::cout << "You can not use send command in this moon" << std::endl;
                        }
                        else {
                            // Check if arguments vector is not empty and the first argument is not empty
                            if (!arguments.empty() && !arguments[0].empty()) {
                                int count = std::stoi(arguments[0]);
                                moon.sendEmployees(g, count);
                            }
                            else {
                                std::cout << "Bad command, the syntax is: send numberOfEmployees" << std::endl;
                                break;
                            }
                            
                        }
                    }          
                    else if (command == "leave") {
                        std::cout << orbitingMoon << std::endl;
                        moonManager.moonWeatherMap.clear();
                        moon.onDayBegin(g);
                        orbitPhase = true;
                        break;
                    }
                   
                    else if (command == "land") {
                        std::cout << "You already landed on " << getOrbitingMoon() << std::endl;
                    }
                    else if (command == "route") {
                        std::cout << "Can not use this command" << std::endl;

                    }
                }
            }
        }
        else {
            foundPhase = false;
        }
        if (!foundPhase) {
            std::cout << "Invalid Command!!" << std::endl;
        }

    }
}