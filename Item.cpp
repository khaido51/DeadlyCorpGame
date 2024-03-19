#include "Item.h"

Item::Item()
{
}

Item::Item(std::string _name, double _price)
{
    name = _name;
    price = _price;
}

std::string Item::getName()
{
    return std::string();
}

double Item::getPrice()
{
    return 0.0;
}
