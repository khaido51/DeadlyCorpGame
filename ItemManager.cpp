#include "ItemManager.h"

//Declaring a list of command that ItemManager class handle
const std::list<std::string> ItemManager::commands = { "inventory", "store", "buy" };
//Create a vector with Item type to store a list of items in ItemManager class
std::vector<Item*> ItemManager::items;
std::vector<std::string> arguments;
std::string inventory[7] = {};

ItemManager::ItemManager()
{

}

//create new Item and store item in items vector
void ItemManager::registerItem(Item* item)
{
    items.push_back(item);
}

//loop to show item's details in vector of items
void ItemManager::showAllItems()
{
    for (const auto& item : items) {
        std::cout << item->getName() << " " << item->getPrice() << std::endl;
    }
}

//proccessing commands
void ItemManager::processCommand(const std::string& command)
{
    std::string itemManagerCommand = " ";
    while (true) {
        //loop through the list to get all valid commands
        for (const auto& validCommand : commands) {
            //check if command passing from main
            if (command == validCommand) {
                std::cout << std::endl;
                std::cout << "Welcome to the Corporation Store" << std::endl;
                std::cout << "Use the word BUY on any item" << std::endl;
                std::cout << "-------------------------------------------" << std::endl;
                showAllItems();
                break;

                std::cin >> itemManagerCommand;
                std::getline(std::cin >> std::ws, itemManagerCommand);

                if (!itemManagerCommand.empty()) {
                    if (command == "store") {
                        showAllItems();
                        break;
                    }
                    else if (command == "inventory") {

                    }
                    else {
                        util::splitArguments(itemManagerCommand, arguments);
                        std::string buyWord = arguments[0];
                        if (buyWord == validCommand) {
                            for (auto item : items) {
                                if (itemManagerCommand == "buy " + item->getName()) {
                                    std::cout << "You have purchased " + item->getName() << std::endl;
                                    break;
                                }

                            }
                        }

                    }
                }

            }
            std::cout << "Here" << std::endl;
            std::cout << std::endl;
        }
        break;
    }
}





