#include "ItemManager.h"

//Declaring a list of command that ItemManager class handle
//const std::list<std::string> ItemManager::commands = { "inventory", "store", "buy" };
//Create a vector with Item type to store a list of items in ItemManager class
std::vector<Item*> items;
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
        std::cout << "* " << item->getName() << " // " << "Price: $" << item->getPrice() << std::endl;
    }
}

void ItemManager::showInventory()
{
    for (const auto& purchasedItem: inventory ) {
        std::cout << "* " << purchasedItem << std::endl;
    }
}

//processing commands
void ItemManager::processCommand(const std::string& command, int& balance, std::vector<std::string> arguments, int cargo, int quota)
{


    //All required text
    if (command == "store") {
        std::cout << std::endl;
        std::cout << "Welcome to the Corporation Store" << std::endl;
        std::cout << "Use the word BUY on any item" << std::endl;
        std::cout << "-------------------------------------------" << std::endl;

        showAllItems();
        std::cout << std::endl;
        std::cout << "Your balance is: $" << balance << std::endl;
        std::cout << std::endl;

    }

    if (command == "buy") {
        bool foundItem = false; //use it as a flag when user input does not match with item name
        //loop to get all item in set of items
        for (auto item : items) {
            //convert itemName to lower case
            const std::string& itemName = item->getName();
            std::string lowerItemName = itemName;
            util::lower(lowerItemName);

            if (lowerItemName == arguments[0]) {
                //check balance to buy appropriate item
                if (balance >= item->getPrice()) {
                    //add item to set of inventory
                    auto result = inventory.insert(item->getName());
                    //check for existing item using second function in SET
                    if (result.second) {
                        foundItem = true;
                        std::cout << "Successfully bought " << item->getName() << std::endl;
                        //deducting balance value from item price.
                        balance = balance - item->getPrice();
                        std::cout << std::endl;
                        std::cout << "Your balance is: $" << balance << std::endl;
                        std::cout << std::endl;

                        break;
                    }
                    else {
                        std::cout << "The item already existed your inventory" << std::endl;
                        break;
                    }
                }
                else {
                    std::cout << "You do not have sufficient fund to purchase the item!" << std::endl;
                }

                break;
            }

        }
        //Catch error and ask user to re enter.
        if (!foundItem) {
            std::cout << "Item name does not match. Please re-enter item name" << std::endl;
        }   
        
    }

    if (command == "inventory") {
        std::cout << "Your inventory have the following items: " << std::endl;
        std::cout << "-----------------------------------------" << std::endl;

        if (inventory.empty()) {
            std::cout << "You have not purchased any item yet!!" << std::endl;
         
            std::cout << std::endl;
        }
        showInventory();
        std::cout << std::endl;
        std::cout << "Your balance is: $" << balance << "(quota is " << quota << ")" << std::endl;
        std::cout << "Cargo value: " << cargo << std::endl;
        std::cout << std::endl;
        return;
    }
  
}





