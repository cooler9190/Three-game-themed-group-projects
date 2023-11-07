#ifndef HERO_HPP_
#define HERO_HPP_

#include "Spell.hpp"
#include "Defines.hpp"
#include <string>
#include <map>
#include <memory>

class Hero {
    public:
    Hero(const std::string& name, int mana, int manaRegen);

    void castSpell(SpellType type);

    virtual void regenMana();

    virtual void specialAbility() = 0;

    protected:
    std::string m_name;
    int m_mana;
    int m_manaRegen;
    const int m_maxMana;
    std::map<SpellType, std::unique_ptr<Spell>> m_spells;
};

#endif /* HERO_H_ */