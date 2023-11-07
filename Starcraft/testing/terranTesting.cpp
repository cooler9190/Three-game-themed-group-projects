#include "../include/Viking.hpp"
#include "../include/BattleCruser.hpp"
#include "../include/BattleField.h"

#include <iostream>
#include <vector>
#include <memory>

int main()
{
    std::string input = "vbvb";
    BattleField field;
    std::vector<std::unique_ptr<TerranFleet>> ships;

    //Test for the GenerateTerranFleet function!
    field.generateTerranFleet(input, ships);

    for (const auto& ship : ships)
    {
        std::cout << "Health: " << ship->getHealth() << "    Damage:  " << ship->getDamage() << std::endl;
    }
    ships[0]->takeDamage(10);
    std::cout << "The new health of v1 is:  " << ships[0]->getHealth() << std::endl;
    ships[1]->takeDamage(60);
    std::cout << "The new health of b1 is:  " << ships[1]->getHealth() << std::endl;

    //This is the test for BattleCruser Special ability!
    for (int i = 0; i < 11; ++i)
    {
        std::cout << ships[1]->attack() << ' ';
    }
    std::cout << std::endl;

    //Test for Viking basic atack(without the special)
    for (int i = 0; i < 3; ++i)
    {
        std::cout << ships[0]->attack() << ' ';
    }

    //Test v1 when atacking Phoenix and Carrier
}