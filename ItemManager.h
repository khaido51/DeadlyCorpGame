#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H

#include "Item.h"
#include "util.h"
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <set>


class ItemManager {
private:
    
    //static const std::list<std::string> commands;
    Item* item;

public:
    std::vector<Item*> items;
    std::vector<std::string> arguments;
    std::set<Item*> inventory;

public:
    ItemManager();
    ~ItemManager();
    void createItems();
    void showAllItems();
    void showInventory();
    std::string lowerItemName(Item* item);
    const std::vector<Item*>& getItems() const;
    void processCommand(const std::string& command, int& balance, std::vector<std::string> arguments, int cargo, int quota);
    void registerItem(Item* item);
    void checkExistingItem(std::string argument, int& balance);
    Item* findItemInInventory();
    std::set<Item*> getInventory();
};
#endif // !ITEMMANAGER_H
