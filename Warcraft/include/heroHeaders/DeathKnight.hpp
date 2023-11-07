#include "Hero.hpp"

class DeathKnight : public Hero{
    public:
    DeathKnight(const std::string& name, int mana, int baseManaRegenRate);

    void specialAbility() override;
};