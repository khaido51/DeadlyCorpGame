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
    static std::vector<Item*> items;
    std::vector<std::string> arguments;
    std::set<std::string> inventory;

public:
    ItemManager();
    void showAllItems();
    void showInventory();
    void processCommand(const std::string& command, int& balance);
    void registerItem(Item* item);
};
#endif // !ITEMMANAGER_H
