#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

class Item {
private:
    std::string name;
    int price;
    float scrapValueMultiplier;
    float explorerSurvivalChanceMultiplier;
    float operatorSurvivalChanceMultiplier;
    float explorerSaveChance;
    float lootRecoveryMultiplier;
    
public:
    Item();
    Item(std::string _name, int _price, float _scrapValueMultiplier, float _explorerSurvivalChanceMultiplier, float _operatorSurvivalChanceMultiplier, float _explorerSaveChance, float _lootRecoveryMultiplier);
    std::string getName();
    int getPrice();
    float getScrapValueMultiplier();
    float getExplorerSurvivalChanceMultiplier();
    float getOperatorSurvivalChanceMultiplier();
    float getExplorerSaveChance();
    float getLootRecoveryMultiplier();
};


#endif