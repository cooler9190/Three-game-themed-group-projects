#include "DrawRanger.hpp"
#include <iostream>

DrawRanger::DrawRanger(const std::string& name, int mana, int manaRegen) 
    : Hero(name, mana, manaRegen) {
        Spell basicSpell(DRAW_RANGER_BASIC_SPELL_NAME, DRAW_RANGER_BASIC_SPELL_MANA_COST, [this]() {specialAbility();});
        std::unique_ptr<Spell> basicPtr(new Spell(basicSpell));
        m_spells[BASIC] = std::move(basicPtr);

        Spell ultimateSpell(DRAW_RANGER_ULTIMATE_SPELL_NAME, DRAW_RANGER_ULTIMATE_SPELL_MANA_COST);
        std::unique_ptr<Spell> ultimatePtr(new Spell(ultimateSpell));
        m_spells[ULTIMATE] = std::move(ultimatePtr);
    }

void DrawRanger::specialAbility() {
    std::cout << m_name << CASTS_STR << DRAW_RANGER_BASIC_SPELL_NAME<< FOR_STR << ZERO_COST << MANA_STR << std::endl;
}