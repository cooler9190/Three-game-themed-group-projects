#include "Hero.hpp"

class DrawRanger : public Hero {
    public:
    DrawRanger(const std::string& name, int maxMana, int baseManaRegenRate);

    void specialAbility() override;
};