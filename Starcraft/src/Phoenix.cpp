#include "Phoenix.hpp"
#include "Defines.hpp"

Phoenix::Phoenix() : ProtossFleet(PHOENIX_HEALTH, PHOENIX_SHIELD, PHOENIX_DAMAGE) {}

void Phoenix::executeSpecial1() {
    if(m_shield == PHOENIX_SHIELD) {
        return;
    } else {
        m_shield += PHOENIX_SHIELD_REGENERATE_RATE;
        if(m_shield > PHOENIX_SHIELD) {
            m_shield = PHOENIX_SHIELD;
        }
    }
}

std::string Phoenix::getShipType() const {
    return stringify(PHOENIX);
}

