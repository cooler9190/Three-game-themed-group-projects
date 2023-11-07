#include "Spell.hpp"
#include "Defines.hpp"
#include <iostream>

Spell::Spell(const std::string& name, int manaCost, SpecialAbilityCallable special)
    : m_spellName(name)
    , m_manaCost(manaCost)
    , m_specialAbility(special)
    {}

void Spell::executeSpecialAbility() {
    if (m_specialAbility) {
        m_specialAbility();
    }
}

std::string Spell::getName() const {
    return m_spellName;
}

int Spell::getManaCost() const {
    return m_manaCost;
}