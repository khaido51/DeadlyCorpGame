#include "ItemManager.h"

//Declaring a list of command that ItemManager class handle
//const std::list<std::string> ItemManager::commands = { "inventory", "store", "buy" };
//Create a vector with Item type to store a list of items in ItemManager class
std::vector<Item*> ItemManager::items;
std::vector<std::string> arguments;
std::set<std::string*> inventory;

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

void ItemManager::showInventory()
{
    for (const auto& purchasedItem: inventory ) {
        std::cout << purchasedItem << std::endl;
    }
}

//proccessing commands
void ItemManager::processCommand(const std::string& command, int& balance)
{
    if (command == "store") {
        std::cout << std::endl;
        std::cout << "Welcome to the Corporation Store" << std::endl;
        std::cout << "Use the word BUY on any item" << std::endl;
        std::cout << "-------------------------------------------" << std::endl;

        showAllItems();
        std::cout << std::endl;
        std::cout << "Your balance is: $" << balance << std::endl;
        std::cout << std::endl;

        while (true) {
            //after command store now they can use Buy command
            std::string itemManagerCommand = " ";
            std::getline(std::cin >> std::ws, itemManagerCommand);
            util::splitArguments(itemManagerCommand, arguments);


            if (itemManagerCommand == "buy") {
                for (auto item : items) {
                    if (item->getName() == arguments[0]) {
                        
                        auto result = inventory.insert(item->getName());
                        if (result.second) {
                            std::cout << "Successfully bought " << item->getName() << std::endl;
                            balance = balance - item->getPrice();
                            std::cout << std::endl;
                            std::cout << "Your balance is: $" << balance << std::endl;
                            std::cout << std::endl;
                        }
                        else {
                            std::cout << "The item already existed your inventory" << std::endl;
                        }
                       
                        break;

                    }
                    
                }
            }
            else if (itemManagerCommand == "inventory") {
                std::cout << "Your inventory have the following items: " << std::endl;
                std::cout << "-----------------------------------------" << std::endl;
                if (inventory.empty()) {
                    std::cout << "You have not purchased any item yet!!" << std::endl;
                    std::cout << "Your balance is: $" << balance << std::endl;
                    std::cout << std::endl;
                }
                showInventory();
                std::cout << std::endl;
                std::cout << "Your balance is: $" << balance << std::endl;
                return;
            }
            else {
                std::cout << "Invalid Command!!" << std::endl;
            }
        }

        return;
        
    }
    //if command == inventory => show all available items/ else no items show
    if (command == "inventory") {
        std::cout << "Your inventory have the following items: " << std::endl;
        std::cout << "-----------------------------------------" << std::endl;
        std::cout << "Your balance is: $" << balance << std::endl;
        if(inventory.empty()){
            std::cout << "You have not purchased any item yet!!" << std::endl;
            std::cout << "Your balance is: $" << balance << std::endl;
            std::cout << std::endl;
        }
        showInventory();
        std::cout << std::endl;
        std::cout << "Your balance is: $" << balance << std::endl;
        return;
        
    }

    
}





