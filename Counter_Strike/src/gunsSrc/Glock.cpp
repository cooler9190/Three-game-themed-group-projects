#include "Glock.hpp"

Glock::Glock(int damagePerRound, int clipSize, int remainingAmmo)
    : Pistol(damagePerRound, clipSize, remainingAmmo) {}

DamageOutput Glock::fire() {
    DamageOutput damage;
    for (int i = 0; i < GeneralDefines::GLOCK_BULLETS_TO_FIRE; ++i) {
        if (m_currClipBullets != GeneralDefines::ZERO_AMMO) {
            int armorDamage = (PistolPercentDamage::GLOCK_ARMOR * m_damagePerRound) / 100;
            int healthDamage = (PistolPercentDamage::GLOCK_HEALTH * m_damagePerRound) / 100;

            std::pair<int, int> damagePair(armorDamage, healthDamage);

            damage.push_back(damagePair);

            --m_currClipBullets;
        } else {
            reload();
            return damage;
        }
    }
    return damage;
}

