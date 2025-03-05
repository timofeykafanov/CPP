#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"

class HumanB {
private:
    std::string name;
    Weapon* weapon;

public:
    HumanB(std::string humanName);

    void setWeapon(Weapon& humanWeapon);

    void attack();
};

#endif // HUMANB_HPP