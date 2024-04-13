// DeadlyCorpGame.cpp : Defines the entry point for the application.
//

#include "DeadlyCorpGame.h"
#include "Game.h"
#include "Item.h"
#include "Moon.h"
#include "MoonManager.h"
#include "AbstractMoon.h"
#include "ItemManager.h"
#include <iostream>
#include <string>
#include <list>
#include "util.h"




int main()
{

    MoonManager moonManager;
    ItemManager itemManager;


    Game game;
    game.initializeGame();
    game.run(game);

    std::cout << "Press Enter to exit...";

    // Wait for Enter key press
    std::cin.get();
   

    return 0;

}
