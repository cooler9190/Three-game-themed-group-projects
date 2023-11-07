#ifndef VIKING_HPP
#define VIKING_HPP

#include "TerranFleet.hpp"
#include <string>

class Viking : public TerranFleet {
    public:
    Viking();

    int executeSpecial() const override;

    std::string getShipType() const override;
};

#endif //VIKING_HPP