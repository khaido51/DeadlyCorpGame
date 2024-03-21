#include "Item.h"

Item::Item()
{
}

Item::Item(std::string _name, int _price)
{
    name = _name;
    price = _price;
}

std::string Item::getName()
{
    return name;
}

int Item::getPrice()
{
    return price;
}
