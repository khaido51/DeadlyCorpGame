#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

class Item {
private:
    std::string name;
    int price;
    
public:
    Item();
    Item(std::string _name, int _price);
    std::string getName();
    int getPrice();
};


#endif