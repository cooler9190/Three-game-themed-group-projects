#include "Hero.hpp"

class Archmage : public Hero {
    public:
    Archmage(const std::string& name, int mana, int manaRegen, int manaRegenModifier);

    void specialAbility() override;
    
    void regenMana() override;

    private:
    int m_multipltier;
};