#include "Casting.hpp"

#include <iostream>
#include <sstream>

#include "Defines.hpp"
#include "Archmage.hpp"
#include "DeathKnight.hpp"
#include "DrawRanger.hpp"

// Should activate Polymorphism
void performCasting() {
    std::string name;
    int maxMana = 0;
    int baseManaRegenRate = 0;
    int manaRegenModifier = 0;  
    
    std::cin >> name >> maxMana >> baseManaRegenRate >> manaRegenModifier;
    Archmage archmage(name, maxMana, baseManaRegenRate, manaRegenModifier);  
    
    std::cin >> name >> maxMana >> baseManaRegenRate;
    DeathKnight deathKnight(name, maxMana, baseManaRegenRate);  
    
    std::cin >> name >> maxMana >> baseManaRegenRate;
    DrawRanger drawRanger(name, maxMana, baseManaRegenRate);  
    
    std::cin.ignore();  
    
    std::string input;
    getline(std::cin, input);

    std::istringstream sstr(input);
    int currAction = 0;  while (sstr >> currAction) {

    switch (currAction) {
            case ActionType::CAST_BASIC_SPELL:
            archmage.castSpell(BASIC);
            deathKnight.castSpell(BASIC);
            drawRanger.castSpell(BASIC);
            break;      
            
            case ActionType::CAST_ULTIMATE_SPELL:
            // Archmage, DeathKnight, DrawRanger cast ultimate spell
            archmage.castSpell(ULTIMATE);
            deathKnight.castSpell(ULTIMATE);
            drawRanger.castSpell(ULTIMATE);
            break;      
            
            case ActionType::REGENERATE_MANA:
            // Archmage, DeathKnight, DrawRanger regenarate mana
            archmage.regenMana();
            deathKnight.regenMana();
            drawRanger.regenMana();
            break;
        }
    }
}