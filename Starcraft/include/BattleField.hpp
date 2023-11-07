#ifndef BATTLEFIELD_HPP
#define BATTLEFIELD_HPP

#include "ProtossFleet.hpp"
#include "TerranFleet.hpp"

#include <iostream>
#include <memory>
#include <string>
#include <vector>

using protossFleetVector = std::vector<std::unique_ptr<ProtossFleet>>;
using terranFleetVector = std::vector<std::unique_ptr<TerranFleet>>;
using string = const std::string;


class BattleField {
    public:
    void generateTerranFleet(string& terranFleetComposition, terranFleetVector& fleet);
    void generateProtossFleet(string& protossFleetComposition, protossFleetVector& fleet);
    void deathMessage(string& shipType, int index, int destroyedIndex);
    void statusMessage(string& shipType, int index, int health);
    void statusMessage(string& shipType, int index, int health, int shield);//For the status of Protos ships
    template <typename T>
    bool isFleetDestroyed(std::vector<std::unique_ptr<T>>& fleet) { return fleet.empty(); }
    int carrieOverDamage(int excessDamage);
    void terranAttacks(terranFleetVector& terranFleet, protossFleetVector& protossFleet, int battleTurn);
    void protossAttacks(terranFleetVector& terranFleet, protossFleetVector& protossFleet, int battleTurn);
    void startBattle(terranFleetVector& fleetTerran, protossFleetVector& fleetProtoss);
};

#endif // BATTLEFIELD_H
