#ifndef PROTOSS_FLEET_HPP
#define PROTOSS_FLEET_HPP
#define stringify(name) #name

#include <string>

class ProtossFleet {
    public:
    ProtossFleet(int health, int shield, int damage);

    virtual void executeSpecial1() = 0;

    virtual int executeSpecial2() const { return 0; };

    virtual int attack() const;

    virtual void takeDamage(int damage);

    virtual int getHealth() const;

    virtual int getShield() const;

    virtual std::string getShipType() const = 0;

    virtual bool isShipDestroyed() const;

    protected:
    int m_health = 0;
    int m_shield = 0;
    int m_damage = 0;
};

#endif // PROTOSS_FLEET_HPP 
