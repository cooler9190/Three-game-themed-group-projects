#include "Pistol.hpp"

Pistol::Pistol(int damage, int clip, int remainingAmmo)
    : m_damagePerRound(damage), m_clipSize(clip), m_remainingAmmo(remainingAmmo), m_currClipBullets(clip) {
        if(m_damagePerRound % 4 != 0) {
            std::cerr << Messages::ERROR_DAMAGE;
            return;
        }
}

void Pistol::reload() {
    if (m_remainingAmmo == GeneralDefines::ZERO_AMMO) {
        std::cout << Messages::NO_AMMO_LEFT;
    } else {
        int ammoToUse = std::min(m_clipSize, m_remainingAmmo);
        m_remainingAmmo -= ammoToUse;
        m_currClipBullets += ammoToUse;

        std::cout << Messages::RELOADING
                  << Messages::CURRCLIP << m_currClipBullets
                  << Messages::REMAINING_AMMO << m_remainingAmmo << '\n';
    }
}

void Pistol::loadPistol(int damage, int clip, int ammo) {
    m_damagePerRound = damage;
    m_clipSize = clip;
    m_remainingAmmo = ammo;
    m_currClipBullets = clip;
}
