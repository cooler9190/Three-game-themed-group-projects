#include "DesertEagle.hpp"
#include <utility>

DesertEagle::DesertEagle(int damagePerRound, int clipSize, int remainingAmmo)
    : Pistol(damagePerRound, clipSize, remainingAmmo) {}


DamageOutput DesertEagle::fire() {
    DamageOutput damage;
    if (m_currClipBullets == GeneralDefines::ZERO_AMMO) {
        reload();
        return damage;
    }

    int armorDamage = (PistolPercentDamage::DESERT_EAGLE_ARMOR * m_damagePerRound) / 100;
    int healthDamage = (PistolPercentDamage::DESERT_EAGLE_HEALTH * m_damagePerRound) / 100;

    std::pair<int, int> damagePair(armorDamage, healthDamage);

    damage.push_back(damagePair);

    --m_currClipBullets;

    return damage;
}
