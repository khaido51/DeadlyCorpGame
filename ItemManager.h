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
    
    static const std::list<std::string> commands;

public:
    std::vector<Item*> items;
    std::vector<std::string> arguments;
    std::set<std::string> inventory;

public:
    ItemManager();
    void showAllItems();
    void showInventory();
    const std::vector<Item*>& getItems() const;
    void processCommand(const std::string& command, int& balance, std::vector<std::string> arguments, int cargo, int quota);
    void registerItem(Item* item);
};
#endif // !ITEMMANAGER_H
