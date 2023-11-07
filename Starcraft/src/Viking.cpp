#include "Viking.hpp"
#include "Defines.hpp"

Viking::Viking() : TerranFleet(VIKING_DAMAGE, VIKING_HEALTH) {}

int Viking::executeSpecial() const {
    return m_damage * 2;
}

std::string Viking::getShipType() const {
    return stringify(VIKING);
}