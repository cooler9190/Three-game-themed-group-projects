#include "BattleField.hpp"
#include "Defines.hpp"
#include "Phoenix.hpp"
#include "Carrier.hpp"
#include "BattleCruser.hpp"
#include "Viking.hpp"

//make functions int, in order to return for errors
void BattleField::generateProtossFleet(string& protossFleetComposition, protossFleetVector& fleet) {
    for (auto iter = protossFleetComposition.begin(); iter != protossFleetComposition.end(); ++iter) {
        if (*iter == CONSTANTS::P) {
            fleet.push_back(std::make_unique<Phoenix>());
        } else if (*iter == CONSTANTS::C) {
            fleet.push_back(std::make_unique<Carrier>());
        } else {
            std::cerr << CONSTANTS::WRONG_INPUT << std::endl;
        }
    }
}

void BattleField::generateTerranFleet(string& terranFleetComposition, terranFleetVector& fleet) {
    for (auto iter = terranFleetComposition.begin(); iter != terranFleetComposition.end(); ++iter) {
        if (*iter == CONSTANTS::V) {
            fleet.push_back(std::make_unique<Viking>());
        } else if (*iter == CONSTANTS::B) {
            fleet.push_back(std::make_unique<BattleCruser>());
        } else {
            std::cerr << CONSTANTS::WRONG_INPUT << std::endl;
        }
    }
}

void BattleField::deathMessage(string& shipType, int index, int destroyedIndex) {
    std::cout << shipType << CONSTANTS::WITH_ID << index << CONSTANTS::KILLED_ENEMY\
    << destroyedIndex << std::endl; 
}

void BattleField::statusMessage(string& shipType, int index, int health) {
    std::cout << shipType << CONSTANTS::WITH_ID << index << CONSTANTS::HAS << health << CONSTANTS::HEALTH << std::endl; 
}

void BattleField::statusMessage(string& shipType, int index, int health, int shield){
    std::cout << shipType << CONSTANTS::WITH_ID << index << CONSTANTS::HAS << health <<\
    CONSTANTS::HEALTH << CONSTANTS::AND << shield << CONSTANTS::SHIELD_LEFT << std::endl;
}

int BattleField::carrieOverDamage(int excessDamage) {
    excessDamage = -excessDamage;
    int carrieOver = excessDamage - (excessDamage % CARRIER_DAMAGE);

    return carrieOver;
}

void BattleField::terranAttacks(terranFleetVector& terranFleet, protossFleetVector& protossFleet, int battleTurn) {
    for (int i = 0; i < terranFleet.size(); ++i) {
        if(isFleetDestroyed(protossFleet)) {
            break;
        }
        if (terranFleet[i]->getShipType() == CONSTANTS::VIKING &&\
        protossFleet.back()->getShipType() == CONSTANTS::PHOENIX) {
            protossFleet.back()->takeDamage(terranFleet[i]->executeSpecial());
        } else if (terranFleet[i]->getShipType() == CONSTANTS::BATTLE_CRUSER && battleTurn % 5 == 0) {
            protossFleet.back()->takeDamage(terranFleet[i]->executeSpecial());
        } else {
            protossFleet.back()->takeDamage(terranFleet[i]->attack());
        }

        if (protossFleet.back()->isShipDestroyed()) {
            protossFleet.pop_back();
            deathMessage(terranFleet[i]->getShipType(), i, protossFleet.size());
        }
    }

    if(!isFleetDestroyed(protossFleet)) {
        statusMessage(protossFleet.back()->getShipType(), protossFleet.size() - 1,\
        protossFleet.back()->getHealth(), protossFleet.back()->getShield());
    }
}

void BattleField::protossAttacks(terranFleetVector& terranFleet, protossFleetVector& protossFleet, int battleTurn) {
    if(isFleetDestroyed(protossFleet)){
        return;
    }
    for (int i = 0; i < protossFleet.size(); ++i) {
        if(isFleetDestroyed(terranFleet)) {
            break;
        }
        if (protossFleet[i]->getShipType() == CONSTANTS::CARRIER) {
            terranFleet.back()->takeDamage(protossFleet[i]->executeSpecial2());
            int excessDamage = terranFleet.back()->getHealth();
            if (excessDamage < ZERO_HEALTH) {
                terranFleet.pop_back();
                deathMessage(protossFleet[i]->getShipType(), i, terranFleet.size());
                if(isFleetDestroyed(terranFleet)) {
                    break;
                } else {
                    terranFleet.back()->takeDamage(carrieOverDamage(excessDamage));
                }
            }
        } else {
            terranFleet.back()->takeDamage(protossFleet[i]->attack());
        }

        protossFleet[i]->executeSpecial1();

        if (terranFleet.back()->isShipDestroyed()) {
            terranFleet.pop_back();
            deathMessage(protossFleet[i]->getShipType(), i, terranFleet.size());
        }
    }

    if(!isFleetDestroyed(terranFleet)){
        statusMessage(terranFleet.back()->getShipType(), terranFleet.size() - 1, terranFleet.back()->getHealth());
    }
}

void BattleField::startBattle(terranFleetVector& terranFleet, protossFleetVector& protossFleet) {
    int battleTurn = 1;

    while (!isFleetDestroyed(terranFleet) && !isFleetDestroyed(protossFleet)) {
        terranAttacks(terranFleet, protossFleet, battleTurn);
        protossAttacks(terranFleet, protossFleet, battleTurn);
        ++battleTurn;
    }

    if (isFleetDestroyed(terranFleet)) {
        std::cout << CONSTANTS::PROTORSS_WIN << std::endl;
    } else {
        std::cout << CONSTANTS::TERRAN_WIN << std::endl;
    }
}
