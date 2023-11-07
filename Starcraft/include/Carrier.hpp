#ifndef CARRIER_HPP
#define CARRIER_HPP

#include "ProtossFleet.hpp"
#include <string>

class Carrier : public ProtossFleet {
    public:
    Carrier();

    void executeSpecial1() override;

    int executeSpecial2() const override;

    std::string getShipType() const override;
};

#endif //CARRIER_HPP