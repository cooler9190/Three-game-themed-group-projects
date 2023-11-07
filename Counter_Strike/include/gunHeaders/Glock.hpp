#ifndef GLOCK_HPP_
#define GLOCK_HPP_

#include "Pistol.hpp"

class Glock : public Pistol {
    public:
    Glock() = default;
    Glock(int damagePerRound, int clipSize, int remainingAmmo);
    DamageOutput fire() override;
};

#endif // GLOCK_HPP_
