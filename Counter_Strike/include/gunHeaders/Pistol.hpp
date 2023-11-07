#ifndef PISTOL_HPP_
#define PISTOL_HPP_

#include "Defines.hpp"
#include <iostream>
#include <memory>

class Pistol {
public:
    Pistol(int damage, int clip, int remainingAmmo);
    virtual ~Pistol() = default;
    void reload();
    virtual DamageOutput fire() = 0;

    void loadPistol(int damage, int clip, int ammo);

protected:
    int m_damagePerRound = 0;
    int m_clipSize = 0;
    int m_remainingAmmo = 0;
    int m_currClipBullets = 0;
};

#endif /* PISTOL_H_ */
