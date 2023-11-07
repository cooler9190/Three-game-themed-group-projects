#ifndef SPELL_HPP
#define SPELL_HPP

#include <string>
#include <functional>

using SpecialAbilityCallable = std::function<void()>;

class Spell {
    public:
    //maybe pointers
    Spell(const std::string& name, int manaCost, SpecialAbilityCallable special = nullptr);

    void executeSpecialAbility();
    
    std::string getName() const;

    int getManaCost() const;

    private:
    std::string m_spellName;
    int m_manaCost;
    SpecialAbilityCallable m_specialAbility;
};

#endif // SPELL_HPP