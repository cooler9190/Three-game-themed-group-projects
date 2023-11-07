#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Defines.hpp"
#include "Pistol.hpp"
#include <memory>

class Player {
public:
    Player(int health, int armor);

    int buyPistol(PistolType pistolType, int damagePerRound, int clipSize, int remainingAmmo);
    void takeDamage(const DamageOutput& damage);
    bool isAlive() const;
    void printVitalDetails() const;
    DamageOutput shoot();

private:
    int m_health;
    int m_armor;
    std::unique_ptr<Pistol> m_pistol;
};

#endif /* PLAYER_H_ */
