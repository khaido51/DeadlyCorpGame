#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

class Item {
private:
    std::string name;
    double price;
    
public:
    Item();
    Item(std::string _name, double _price);
    std::string getName();
    double getPrice();
};


#endif