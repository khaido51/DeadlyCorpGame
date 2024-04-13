#include "ItemManager.h"

//Declaring a list of command that ItemManager class handle
//const std::list<std::string> ItemManager::commands = { "inventory", "store", "buy" };
//Create a vector with Item type to store a list of items in ItemManager class
std::vector<Item*> items;
std::vector<std::string> arguments;
std::set<Item*> inventory;

ItemManager::ItemManager()
{
    Item* item1 = new Item("Flashlight", 60, 1, 1.05, 1, 0, 1);
    Item* item2 = new Item("Shovel", 100, 1, 1.05, 1, 0, 1);
    Item* item3 = new Item("Pro-flashlight", 200, 1, 1.1, 1, 0, 1);
    Item* item4 = new Item("Teleporter", 300, 1, 1, 1, 0.33, 1);
    Item* item5 = new Item("Inverse-Teleporter", 400, 1.1, 0.8, 1, 0, 1);
    Item* item6 = new Item("Backpack", 500, 1, 1, 1, 0, 1.25);
    Item* item7 = new Item("Hydraulics-Mk2", 1000, 1, 1, 1.25, 1, 1);

    registerItem(item1);
    registerItem(item2);
    registerItem(item3);
    registerItem(item4);
    registerItem(item5);
    registerItem(item6);
    registerItem(item7);
}

ItemManager::~ItemManager()
{
    for (Item* item : items) {
        delete item;
    }
    items.clear();

    for (Item* inventoryItems : inventory) {
        delete inventoryItems;
    }

    inventory.clear();
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
    for (Item* purchasedItem: inventory ) {
        std::cout << "* " << purchasedItem->getName() << std::endl;
    }
}

std::string ItemManager::lowerItemName(Item* item)
{
    const std::string& itemName = item->getName();
    std::string lowerItemName = itemName;
    util::lower(lowerItemName);
    return lowerItemName;
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
        bool existingItem = false;
        //loop to get all item in set of items
        for (Item* item : items) {
            foundItem = false;
            //convert itemName to lower case
            
            std::string itemName = lowerItemName(item);
            util::lower(arguments[0]);

            //check itemname == arguments
            if (itemName == arguments[0]) {
                //check balance to buy appropriate item
                if (balance >= item->getPrice()) {
                    foundItem = true;
                    existingItem = false;
                  
                    //check for existing item in the invetory
                    for (Item* purchasedItem : inventory) {
                        std::string purchasedItemName = lowerItemName(purchasedItem);
                        if (purchasedItemName == arguments[0]) {
                            existingItem = true;
                            std::cout << "The item already existed your inventory" << std::endl;
                            std::cout << std::endl;
                        }  
                    }
                    //if it doesnt exist
                    if (!existingItem) {
                        inventory.insert(item);
                        std::cout << "Successfully bought " << item->getName() << std::endl;
                        //deducting balance value from item price.
                        balance = balance - item->getPrice();
                        std::cout << std::endl;
                        std::cout << "Your balance is: $" << balance << std::endl;
                        std::cout << std::endl;
                    }
                  
                }
                else {
                    foundItem = true;
                    std::cout << "You do not have sufficient fund to purchase the item!" << std::endl;
                    std::cout << std::endl;
                    break;
                }
                break;
            }
       
        }
        //Catch error and ask user to re enter.
        if (!foundItem) {
            std::cout << "Item name does not match. Please re-enter item name" << std::endl;
            std::cout << std::endl;
            
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

const std::vector<Item*>& ItemManager::getItems() const {
    return items;
}

Item* ItemManager::findItemInInventory() {
    for (Item* purchasedItem : inventory) {
        return purchasedItem;
    }
}

std::set<Item*> ItemManager::getInventory()  {
    return inventory;
}



