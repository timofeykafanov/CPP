#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap default constructor called for " << _name << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap constructor called for " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap copy constructor called for " << _name << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called for " << _name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "FragTrap assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

void FragTrap::attack(const std::string& target) {
    if (_energyPoints == 0) {
        std::cout << "FragTrap " << _name << " has no energy points left!" << std::endl;
        return;
    }
    if (_hitPoints == 0) {
        std::cout << "FragTrap " << _name << " has no hit points left!" << std::endl;
        return;
    }
    
    std::cout << "FragTrap " << _name << " attacks " << target 
              << " with a SPECIAL attak, causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _name << " requests high fives from everyone! ✋" << std::endl;
}