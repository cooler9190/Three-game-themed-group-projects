#include "Carrier.hpp"
#include "Defines.hpp"

Carrier::Carrier() : ProtossFleet(CARRIER_HEALTH, CARRIER_SHIELD, CARRIER_DAMAGE){}

void Carrier::executeSpecial1() {
    if(m_shield == CARRIER_SHIELD) {
        return;
    } else {
        m_shield += CARRIER_SHIELD_REGENERATE_RATE;
        if(m_shield > CARRIER_SHIELD) {
            m_shield = CARRIER_SHIELD;
        }
    }
}

int Carrier::executeSpecial2() const {
    if(m_health == CARRIER_HEALTH) {
        return attack() * 8;
    } else {
        return attack() * 4;
    }
}

std::string Carrier::getShipType() const {
    return stringify(CARRIER);
}