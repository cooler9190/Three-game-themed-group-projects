#ifndef TERRANFLEET_HPP
#define TERRANFLEET_HPP
#define stringify(name) #name

#include <string>

class TerranFleet {
    public:
    TerranFleet(int damage, int healt);
    virtual int getHealth() const;

    virtual void takeDamage(int damage);

    virtual int executeSpecial() const = 0;

    virtual int attack() const;

    virtual std::string getShipType() const = 0;
    
    virtual bool isShipDestroyed() const;

    protected:
    int m_damage = 0;
    int m_health = 0;
};

#endif //TERRANFLEET_HPP