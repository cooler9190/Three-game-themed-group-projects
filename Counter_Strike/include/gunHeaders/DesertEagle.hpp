#ifndef DESERTEAGLE_HPP_
#define DESERTEAGLE_HPP_

#include "Pistol.hpp"

class DesertEagle : public Pistol {
public:
    DesertEagle(int damagePerRound, int clipSize, int remainingAmmo);
    DamageOutput fire() override;
};

#endif // DESERTEAGLE_HPP_
