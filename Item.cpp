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
    return name;
}

double Item::getPrice()
{
    return price;
}
