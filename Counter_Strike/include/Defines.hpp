#ifndef DEFINES_HPP_
#define DEFINES_HPP_

#include <vector>
#include <utility>

using DamageOutput = std::vector<std::pair<int, int>>;

enum class PistolType { GLOCK = 0, DESERT_EAGLE = 1 };

namespace GeneralDefines {
    const int PLAYER_ONE = 0;
    const int PLAYER_TWO = 1;
    const int PLAYERS_COUNT = 2;
    const int ZERO_AMMO = 0;
    const int ZERO_HEALTH = 0;
    const int ZERO_ARMOR = 0;
    const int GLOCK_BULLETS_TO_FIRE = 3;
}

namespace PistolPercentDamage {
    const int GLOCK_ARMOR = 50;
    const int GLOCK_HEALTH = 50;
    const int DESERT_EAGLE_ARMOR = 25;
    const int DESERT_EAGLE_HEALTH = 75;
}

namespace Messages {
    constexpr const char* ENEMY_LEFT = "Enemy left with: ";
    constexpr const char* HEALTH_AND_STR = " health and ";
    constexpr const char* ARMOR_STR = " armor";
    constexpr const char* PLAYER_INPUT = "Enter initial health and armor for Player with ID: ";
    constexpr const char* PISTOL_INPUT = "Enter pistol info for Player ";
    constexpr const char* PLAYER_ID = "PlayerID ";
    constexpr const char* PLAYER_WITH_ID = "Player with ID: ";
    constexpr const char* TURN = " turn:\n";
    constexpr const char* WIN = " wins!\n";
    constexpr const char* RELOADING = "Reloading...\n";
    constexpr const char* CURRCLIP = "currClipBullets: ";
    constexpr const char* REMAINING_AMMO = ", remainingAmmo: ";
    constexpr const char* NO_AMMO_LEFT = "No ammo left\n";
    constexpr const char* ERROR_DAMAGE = "Damage must be a multiple of 4!";
    constexpr const char* NEW_LINE = "\n";
}

#endif /* DEFINES_HPP_ */
