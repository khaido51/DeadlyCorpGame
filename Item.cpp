#include "Item.h"

Item::Item()
{
}

Item::Item(std::string _name, int _price, float _scrapValueMultiplier, float _explorerSurvivalChanceMultiplier, float _operatorSurvivalChanceMultiplier, float _explorerSaveChance, float _lootRecoveryMultiplier)
{
    name = _name;
    price = _price;
    scrapValueMultiplier = _scrapValueMultiplier;
    explorerSurvivalChanceMultiplier = _explorerSurvivalChanceMultiplier;
    operatorSurvivalChanceMultiplier = _operatorSurvivalChanceMultiplier;
    explorerSaveChance = _explorerSaveChance;
    lootRecoveryMultiplier = _lootRecoveryMultiplier;
}

std::string Item::getName()
{
    return name;
}

int Item::getPrice()
{
    return price;
}

float Item::getScrapValueMultiplier()
{
    return scrapValueMultiplier;
}

float Item::getExplorerSurvivalChanceMultiplier()
{
    return explorerSurvivalChanceMultiplier;
}

float Item::getOperatorSurvivalChanceMultiplier()
{
    return operatorSurvivalChanceMultiplier;
}

float Item::getExplorerSaveChance()
{
    return explorerSaveChance;
}

float Item::getLootRecoveryMultiplier()
{
    return lootRecoveryMultiplier;
}


