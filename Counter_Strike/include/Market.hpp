#include "Glock.hpp"
#include "DesertEagle.hpp"
#include "Defines.hpp"

#include <map>
#include <memory>

class Market {
    public:
    Market() = default;

    std::map<PistolType, std::unique_ptr<Pistol>> m_pistols;

    void loadPistolStock() {
        std::unique_ptr<Pistol> glockPtr(new Glock(0, 0, 0));
        m_pistols[PistolType::GLOCK] = std::move(glockPtr);

        std::unique_ptr<Pistol> desertEaglePtr(new DesertEagle(0, 0, 0));
        m_pistols[PistolType::DESERT_EAGLE] = std::move(desertEaglePtr);
    }
};