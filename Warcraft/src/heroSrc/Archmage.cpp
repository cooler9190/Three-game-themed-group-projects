#include "Archmage.hpp"
#include <iostream>

Archmage::Archmage(const std::string& name, int mana, int manaRegen, int manaRegenModifier) 
    : Hero(name, mana, manaRegen), 
    m_multipltier(manaRegenModifier) {
        Spell basicSpell(ARCHMAGE_BASIC_SPELL_NAME, ARCHMAGE_BASIC_SPELL_MANA_COST);
        std::unique_ptr<Spell> basicPtr(new Spell(basicSpell));
        m_spells[BASIC] = std::move(basicPtr);

        Spell ultimateSpell(ARCHMAGE_ULTIMATE_SPELL_NAME, ARCHMAGE_ULTIMATE_SPELL_MANA_COST, [this]() {specialAbility();});
        std::unique_ptr<Spell> ultimatePtr(new Spell(ultimateSpell));
        m_spells[ULTIMATE] = std::move(ultimatePtr);
    }

void Archmage::regenMana() {
    m_manaRegen *= m_multipltier;
    if(m_mana < m_maxMana) {
        m_mana += m_manaRegen;
        if(m_mana > m_maxMana) {
            m_mana = m_maxMana;
        }
    }
}

void Archmage::specialAbility() {
    this->regenMana();
}