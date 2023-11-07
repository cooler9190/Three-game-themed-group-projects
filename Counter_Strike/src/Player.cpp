#include "Player.hpp"
#include "Market.hpp"

Player::Player(int health, int armor) : m_health(health), m_armor(armor), m_pistol(nullptr) {}

int Player::buyPistol(PistolType pistolType, int damagePerRound, int clipSize, int remainingAmmo) {
    Market gunMarket;

    gunMarket.loadPistolStock();

    auto desiredPistol = gunMarket.m_pistols.find(pistolType);

    if(desiredPistol != gunMarket.m_pistols.end()) {
        m_pistol = std::move(desiredPistol->second);

    //can be setPistol
        m_pistol->loadPistol(damagePerRound, clipSize, remainingAmmo);
    
        return 0;
    } else {
        return 1;
    }
}

void Player::takeDamage(const DamageOutput& bullets) {
    if(bullets.empty()) {
        return;
    }

    for(const auto& bullet : bullets) {
        if (!isAlive()) {
            break;
        }
        int armorDamage = bullet.first;
        int healthDamage = bullet.second;

        if (m_armor >= armorDamage) {
            m_armor -= armorDamage;
        } else {
            healthDamage += armorDamage - m_armor;
            m_armor = GeneralDefines::ZERO_ARMOR;
        }

        if (m_health >= healthDamage) {
            m_health -= healthDamage;
        } else {
            m_health = GeneralDefines::ZERO_HEALTH;
        }
    
        printVitalDetails();
    }
}

bool Player::isAlive() const {
    return m_health > GeneralDefines::ZERO_HEALTH;
}

void Player::printVitalDetails() const {
    std::cout << Messages::ENEMY_LEFT << m_health << Messages::HEALTH_AND_STR << m_armor << Messages::ARMOR_STR << std::endl;
}

DamageOutput Player::shoot() {
    if (m_pistol) {
        return m_pistol->fire();
    } else {
        std::cout << "No pistol equipped!" << std::endl;
        return DamageOutput();
    }
}