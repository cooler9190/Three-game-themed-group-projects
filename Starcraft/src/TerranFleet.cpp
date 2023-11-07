#include "TerranFleet.hpp"
#include "Defines.hpp"

TerranFleet::TerranFleet(int damage, int healt) {
    m_damage = damage;
    m_health = healt;
}

int TerranFleet::getHealth() const {
    return m_health;
}

int TerranFleet::attack() const {
    return m_damage;
}

void TerranFleet::takeDamage(int damage) {
    m_health -= damage;
}

bool TerranFleet::isShipDestroyed() const {
    return m_health <= ZERO_HEALTH;
}