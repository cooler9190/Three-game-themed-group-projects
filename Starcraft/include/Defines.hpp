#ifndef DEFINES_HPP
#define DEFINES_HPP

#include <string>

enum AirShipDefines {
  BATTLE_CRUSER_HEALTH = 450,
  BATTLE_CRUSER_DAMAGE = 40,

  VIKING_HEALTH = 150,
  VIKING_DAMAGE = 15,

  CARRIER_HEALTH = 200,
  CARRIER_SHIELD = 150,
  CARRIER_DAMAGE = 8,
  CARRIER_SHIELD_REGENERATE_RATE = 40,

  PHOENIX_HEALTH = 90,
  PHOENIX_SHIELD = 90,
  PHOENIX_DAMAGE = 20,
  PHOENIX_SHIELD_REGENERATE_RATE = 20,

  ZERO_HEALTH = 0,
  ZERO_SHIELD = 0
};

enum AirShipType { BATTLE_CRUSER, VIKING, CARRIER, PHOENIX};

enum CarrierDefines { MAX_INTERCEPTORS = 8, DAMAGED_STATUS_INTERCEPTORS = 4 };

enum BattleCruserDefines { YAMATO_CANNON = 5 * BATTLE_CRUSER_DAMAGE };

namespace CONSTANTS {
  const std::string WRONG_INPUT = "Wrong input!";
  const std::string PROTORSS_WIN = "PROTOSS has won!";
  const std::string TERRAN_WIN = "TERRAN has won!";
  const std::string WITH_ID = " with ID: ";
  const std::string HAS = " has ";
  const std::string KILLED_ENEMY = " killed enemy airship with ID: ";
  const std::string HEALTH = " health";
  const std::string SHIELD_LEFT = " shield left";
  const std::string AND = " and ";

  //standart string is not compile time, it's runtime, use constexpr char*
  const std::string VIKING = "VIKING";
  const std::string PHOENIX = "PHOENIX";
  const std::string BATTLE_CRUSER = "BATTLE_CRUSER";
  const std::string CARRIER = "CARRIER";
  //better names
  const char V = 'v';
  const char C = 'c';
  const char B = 'b';
  const char P = 'p';
}

#endif /* DEFINES_H_ */
