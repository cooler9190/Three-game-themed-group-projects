#ifndef BATTLECRUSER_HPP
#define BATTLECRUSER_HPP

#include "TerranFleet.hpp"
#include <string>

class BattleCruser : public TerranFleet {
    public:
    BattleCruser();

    int executeSpecial() const override;

    std::string getShipType() const override;
};

#endif //BATTLECRUSER_HPP