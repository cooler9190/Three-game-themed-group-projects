#include "ProtossFleet.hpp"
#include "Defines.hpp"

ProtossFleet::ProtossFleet(int health, int shield, int damage) {
    m_health = health;
    m_shield = shield;
    m_damage = damage;
}

int ProtossFleet::getHealth() const {
    return m_health;
}

int ProtossFleet::getShield() const {
    return m_shield;
}

int ProtossFleet::attack() const {
    return m_damage;
}

void ProtossFleet::takeDamage(int damage) {
    if(m_shield > ZERO_SHIELD) {
        m_shield -= damage;
        if(m_shield < ZERO_SHIELD) {
            m_health += m_shield;
            m_shield = ZERO_SHIELD;
        }
    } else {
        m_health -= damage;
    }
}

bool ProtossFleet::isShipDestroyed() const {
    return m_health <= ZERO_HEALTH;
}
