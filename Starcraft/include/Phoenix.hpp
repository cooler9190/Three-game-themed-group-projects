#ifndef PHOENIX_HPP
#define PHOENIX_HPP

#include "ProtossFleet.hpp"
#include <string>

class Phoenix : public ProtossFleet {
    public:
    Phoenix();

    void executeSpecial1() override;

    std::string getShipType() const override;
};

#endif //PHOENIX_HPP