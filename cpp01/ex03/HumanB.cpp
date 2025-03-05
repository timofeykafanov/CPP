#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string humanName) 
    : name(humanName), weapon(NULL) {}

void HumanB::setWeapon(Weapon& humanWeapon) {
    weapon = &humanWeapon;
}

void HumanB::attack() {
    if (weapon) {
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    } else {
        std::cout << name << " has no weapon to attack with!" << std::endl;
    }
}