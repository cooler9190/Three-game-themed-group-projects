#include "Hero.hpp"
#include <iostream>

Hero::Hero(const std::string& name, int mana, int manaRegen) 
    : m_name(name)
    , m_mana(mana)
    , m_manaRegen(manaRegen)
    , m_maxMana(mana)
    {}

void Hero::regenMana() {
    if(m_mana < m_maxMana) {
        m_mana += m_manaRegen;
        if(m_mana > m_maxMana) {
            m_mana = m_maxMana;
        }
    }
}

void Hero::castSpell(SpellType type) {
    auto iter = m_spells.find(type);
    if (iter != m_spells.end()) {
        std::unique_ptr<Spell>& spell = iter->second;
        int manaCost = spell->getManaCost();
        std::string spellName = spell->getName();

        if (m_mana >= manaCost) {
            std::cout << m_name << CASTS_STR  << spellName
            << FOR_STR << manaCost << MANA_STR << std::endl;

            m_mana -= manaCost;

            spell->executeSpecialAbility(); 
        } else {
            std::cout << m_name << NOT_ENOUGH_MANA << spellName << std::endl;
        }
    }
}