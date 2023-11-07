#include "BattleCruser.hpp"
#include "Defines.hpp"

BattleCruser::BattleCruser() : TerranFleet(BATTLE_CRUSER_DAMAGE, BATTLE_CRUSER_HEALTH){}

int BattleCruser::executeSpecial() const {
    return YAMATO_CANNON;
}

std::string BattleCruser::getShipType() const {
    return stringify(BATTLE_CRUSER);
}
