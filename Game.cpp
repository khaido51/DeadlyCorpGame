#include "Game.h"

Game::Game(): rng(rd())
{
}

void Game::initializeGame()
{
    //itemManager.createItems();
    //moonManager.createMoons();

    orbitingMoon = moonManager.getOrbitingMoon()[0]->name();
    //std::cout << "Current Moon is " << orbitingMoon << std::endl;
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
    std::cout << "Current quota: $" << quota << "( " << 4 - currentDay << " days left to meet quota)" << std::endl;
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

void Game::newDay(Game& g)
{
    moonManager.moonWeatherMap.clear();
    numberOfEmployees = 4;
    moon.onDayBegin(g);

}

void Game::setCargo(int newCargo)
{
    cargo = newCargo;
}

void Game::setQuota(int newQuota)
{
    quota = newQuota;
}

void Game::setBalance(int newBalance)
{
    balance = newBalance;
}

void Game::setNumberOfEmployees(int num)
{
    numberOfEmployees = num;
}

int Game::getNumberOfEmployees()
{
    return numberOfEmployees;
}

void Game::setCurrentDay(int newDay)
{
    currentDay = newDay;
}


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

float Game::randomFloat()
{
    std::uniform_real_distribution<float> realDistribution;
    float myRandomNumber = realDistribution(rng);
    return myRandomNumber;
}

MoonWeather Game::getRandomWeather()
{
    std::uniform_int_distribution<int> weatherDistribution(0, 3);
    int myRandomWeather = weatherDistribution(rng);
    MoonWeather randomMoonWeather = static_cast<MoonWeather>(myRandomWeather);

    return randomMoonWeather;
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


int Game::gameSimulation(int amount) {
    //numOfOperator = aliveEmployees - numExplorers
    //explorerSurvivalChance = explorerBaseSurvivalChance * explorerSurvivalChanceMultiplier
    //operatorSurvivalChance = 1.0 * operatorSurvivalChanceMultiplier
    int numOfExplorer = amount;
    int numOfOperator = 4 - amount;
    float exploreBaseSurvivalChance = 0.0;
    float explorerSurvivalChanceMultiplier;
    float explorerSurvivalChance = 1;
    float scrapValueMultiplier = 1;
    float explorerSaveChance = 0;
    float lootRecoveryMultiplier = 0.5;
    float operatorSurvivalChance = 1;
   
    //totalRevenue = 0 
    //deadExplorers = 0 
    int totalRevenue = 0;
    int deadExplorers = 0;

    std::string moonName = getOrbitingMoon();
    MoonWeather moonWeather = getMoonWeather();


    switch (moonWeather) {
    case MoonWeather::Clear:
        scrapValueMultiplier *= 1;
        explorerSurvivalChance *= 1;
        operatorSurvivalChance *= 1;
        std::cout << "";
        break;
    case MoonWeather::Stormy:
        scrapValueMultiplier *= 0.75;
        explorerSurvivalChance *= 1;
        operatorSurvivalChance *= 1;
        std::cout << "(Stormy)";
        break;
    case MoonWeather::Flooded:
        scrapValueMultiplier *= 1;
        explorerSurvivalChance *= 0.7;
        operatorSurvivalChance *= 1;
        std::cout << "(Flooded)";
        break;
    case MoonWeather::Eclipsed:
        scrapValueMultiplier *= 1;
        explorerSurvivalChance *= 0.9;
        operatorSurvivalChance *= 0.7;
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
   // std::cout << explorerSurvivalChance << std::endl;


    //loop inventory to get item
    //single item

    std::set<Item*> inventory = itemManager.getInventory();
    for (auto item : inventory) {
        explorerSurvivalChanceMultiplier = item->getExplorerSurvivalChanceMultiplier();
        scrapValueMultiplier *= item->getScrapValueMultiplier();
        explorerSurvivalChance *= explorerSurvivalChanceMultiplier;
        if (item->getName() == "Teleporter") {
            explorerSaveChance = 0.33;
        }
        if (item->getName() == "Backpack") {
            lootRecoveryMultiplier = lootRecoveryMultiplier * item->getLootRecoveryMultiplier();
        }
        if (item->getName() == "Hydraulics-Mk2") {
            operatorSurvivalChance = operatorSurvivalChance * item->getOperatorSurvivalChanceMultiplier();
        }

    }


    //REPEAT numExplorers TIMES: 
    for (int i = 0; i < numOfExplorer; i++) {
        //  revenue = randomIntBetween(minScrapValue * scrapValueMultplier, maxScrapValue * scrapValueMultplier)
        int revenue = getRandomInt(float(moonPtr->getMinimumScrapValue() * scrapValueMultiplier), float(moonPtr->getMaxScrapValue() * scrapValueMultiplier));

        //IF randomFloat01() < explorerSurvivalChance: 
        if (randomFloat() < explorerSurvivalChance) {
            //This employee made it out alive 
            //  totalRevenue = totalRevenue + revenue
            totalRevenue = totalRevenue + revenue;
        }
        //ELSE randomFloat01() >= explorerSaveChance: 
        else if (randomFloat() >= explorerSaveChance) {
            //This employee died and was NOT saved 
            // totalRevenue = totalRevenue + revenue * lootRecoveryMultiplier(default = 0.5, if user has backpack = 1.25 * 0.5)
            totalRevenue = totalRevenue + revenue * lootRecoveryMultiplier;
            // deadExplorers = deadExplorers + 1
            deadExplorers = deadExplorers + 1;
        }

        //If all employees died
        if (deadExplorers == numOfExplorer) {
            //all cargo is lost
            totalRevenue = 0;
        }
    }

    int deadOperators = 0;

    for (int i = 0; i < numOfOperator; i++) {
        if (randomFloat() >= operatorSurvivalChance) {
            deadOperators++;
        }
    }

   
   
    //get total of employee
    int aliveEmployees = getNumberOfEmployees();//4
    //get alive employees after exploring
    aliveEmployees = aliveEmployees - deadExplorers - deadOperators;
    //set new employee
    setNumberOfEmployees(aliveEmployees);
    //calculate number of explorer alive after exploring
    numOfExplorer = numOfExplorer - deadExplorers;
  
    
  

    //if all dies
    if (numOfExplorer == 0) {
        std::cout << "None of the employees managed to make it back. " << aliveEmployees << " left." << std::endl;
    }
    else {
        std::cout << numOfExplorer << " made it back to the ship, bring $" << totalRevenue << " worth of scrap. " << deadExplorers << " died" << std::endl;
    }

    //calculate new cargo = totalRevenue
    totalRevenue = totalRevenue + showCargo();
    setCargo(totalRevenue);

    return deadExplorers, deadOperators, totalRevenue;
    

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
    std::vector<std::string> orbitingPhase = { "moons", "store", "route", "inventory", "buy","land", "exit", "send", "sell", "leave"};
    //list of command in landing phase
    std::vector<std::string> landingPhase = { "moons", "store","inventory", "buy","land", "exit", "send", "sell", "leave", "route"};
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
                        if (arguments.empty()) {
                            std::cout << "Bad Command, the syntax is route moonName." << std::endl;
                        }
                        else {
                            moonManager.processCommands(command, orbitingMoon, balance, arguments, moonWeather);
                        }
                        
                    }
                    else if (command == "buy") {
                        if (arguments.empty()) {
                            std::cout << "Bad Command, the syntax is buy itemName." << std::endl;
                        }
                        else {
                            itemManager.processCommand(command, balance, arguments, cargo, quota);
                        }
                    }
                    else if (command == "land") {
                        processCommand(command, orbitingMoon, moonWeather);
                        setOrbitingMoon(orbitingMoon);
                        setMoonWeather(moonWeather);
                        //std::cout << "You are orbiting to " << getOrbitingMoon() << std::endl;
                        orbitPhase = false;
                        break;
                    }
                    else if (command == "sell") {
                        std::cout << "Command is not valid at this phase" << std::endl;
                    }
                    else if (command == "send") {
                        std::cout << "Command is not valid at this phase" << std::endl;
                    }
                    else if (command == "leave") {
                        std::cout << "Command is not valid at this phase" << std::endl;
                    }
                    else if (command == "exit") {
                        exitGame();
                    }
                    break;
                }
                else {
                    foundPhase = false;
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
                        if (arguments.empty()) {
                            std::cout << "Bad Command, the syntax is buy itemName." << std::endl;
                        }
                        else {
                            itemManager.processCommand(command, balance, arguments, cargo, quota);
                        }
                    }

                    else if (command == "sell") {     
                        if (orbitingMoon != "Corporation") {
                            std::cout << "You can not use sell command in this moon " << std::endl;
                        }
                        else {
                            if (arguments.empty()) {
                                count = showCargo();
                                moon.sellCargo(g, count);
                            }
                            else if (!arguments.empty() && !arguments[0].empty()) {
                                count = util::parsePositiveInt(arguments[0]);
                                moon.sellCargo(g, count);
                            }
                            else {
                                std::cout << "You must enter a valid number!!" << std::endl;
                                break;
                            }
                                          
                        }     
                    }
                    else if (command == "send") {
                        if (orbitingMoon == "corporation") {
                            std::cout << "You can not use send command in this moon" << std::endl;
                        }
                        else {
                            // Check if arguments vector is not empty and the first argument is not empty
                            if (!arguments.empty() && !arguments[0].empty()) {
                                //count = std::stoi(arguments[0]);
                                count = util::parsePositiveInt(arguments[0]);
                                if (count <= getNumberOfEmployees()) {  
                                    moon.sendEmployees(g, count);
                                }
                                else {
                                    std::cout << "You only have " << getNumberOfEmployees() << std::endl;
                                }            
                            }
                            else {
                                std::cout << "Bad command, the syntax is: send numberOfEmployees" << std::endl;
                                break;
                            }

                            if (getNumberOfEmployees() == 0) {
                                setCargo(0);
                                std::cout << std::endl;
                                std::cout << std::endl;
                                std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
                                std::cout << "All the employees died and the scrap is lost." << std::endl;
                                std::cout << "Autopilot will now bring the ship back to orbit." << std::endl;
                                std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
                                moonManager.moonWeatherMap.clear();
                                numberOfEmployees = 4;
                                moon.onDayBegin(g);
                                orbitPhase = true;
                                break;
                            }
                            
                        }
                    }
                    else if (command == "leave") {
                        //std::cout << orbitingMoon << std::endl;
                        //Clear the map for a new day
                        if (currentDay % 4 == 0) {
                            if (balance >= quota) {
                                quota = quota * 150 / 100;
                                setQuota(quota);
                                
                                std::cout << "---------------------" << std::endl;
                                std::cout << "CONGRATULATIONS ON MAKING QUOTA" << std::endl;
                                std::cout << "New Quota: $" << showQuota() << std::endl;       
                                std::cout << "---------------------" << std::endl;
                            }
                            else {
                                std::cout << "---------------------" << std::endl;
                                std::cout << "YOU'RE FAILED MAKING QUOTA!!" << std::endl;
                                std::cout << ">>>>>>>> GAME OVER <<<<<<<<" << std::endl;
                                std::cout << "---------------------" << std::endl;
                                std::cout << std::endl;
                                std::cout << "You did not meet quota in time, and your employees have been fired. You kept them alive for " << g.showCurrentDay() << " days" << std::endl;
                                //Exit the program
                                exitGame();                              
                            }
                        }

                        moonManager.moonWeatherMap.clear();
                        numberOfEmployees = 4;
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
                    else if (command == "exit") {
                        exitGame();
                    }
                    break;
                }
                else {
                    foundPhase = false;
                }
            }
        }
       
        if (!foundPhase) {
            std::cout << "Invalid Command!!" << std::endl;
            std::cout << std::endl;
            std::cout << std::endl;
        }
    }
    
}

void Game::exitGame()
{
    exit(0);
}