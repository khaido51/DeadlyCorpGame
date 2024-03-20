#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H

#include "Item.h"
#include "util.h"
#include <iostream>
#include <string>
#include <list>
#include <vector>

class ItemManager {
private:
   
    static const std::list<std::string> commands;
    static std::vector<Item*> items;
    std::vector<std::string> arguments;
    std::string inventory[7];

public:
    ItemManager();
    void showAllItems();
    void processCommand(const std::string& command);
    void registerItem(Item* item);
};
#endif // !ITEMMANAGER_H
