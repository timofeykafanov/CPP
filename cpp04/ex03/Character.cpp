#include "Character.hpp"
#include <iostream>

Character::Character() : name("Unknown") {
    std::cout << "Character default constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        this->inventory[i] = NULL;
    }
}

Character::Character(std::string const & name) : name(name) {
    std::cout << "Character name constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        this->inventory[i] = NULL;
    }
}

Character::Character(const Character& other) : name(other.name) {
    std::cout << "Character copy constructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        this->inventory[i] = NULL;
    }
    
    for (int i = 0; i < 4; i++) {
        if (other.inventory[i])
            this->inventory[i] = other.inventory[i]->clone();
    }
}

Character& Character::operator=(const Character& other) {
    std::cout << "Character assignment operator called" << std::endl;
    if (this != &other) {
        this->name = other.name;
        
        for (int i = 0; i < 4; i++) {
            if (this->inventory[i])
                delete this->inventory[i];
            this->inventory[i] = NULL;
        }
        
        for (int i = 0; i < 4; i++) {
            if (other.inventory[i])
                this->inventory[i] = other.inventory[i]->clone();
            else
                this->inventory[i] = NULL;
        }
    }
    return *this;
}

Character::~Character() {
    std::cout << "Character destructor called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i])
            delete this->inventory[i];
    }
}

std::string const & Character::getName() const {
    return this->name;
}

void Character::equip(AMateria* m) {
    if (!m) {
        std::cout << "Cannot equip NULL Materia" << std::endl;
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        if (this->inventory[i] == NULL) {
            this->inventory[i] = m;
            std::cout << "Materia equipped in slot " << i << std::endl;
            return;
        }
    }
    
    std::cout << "Inventory is full, cannot equip more Materias" << std::endl;
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4) {
        std::cout << "Invalid inventory index" << std::endl;
        return;
    }
    
    if (this->inventory[idx]) {
        std::cout << "Materia unequipped from slot " << idx << std::endl;
        this->inventory[idx] = NULL;
    } else {
        std::cout << "No Materia in slot " << idx << " to unequip" << std::endl;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4 || !this->inventory[idx]) {
        std::cout << "Cannot use: invalid index or no materia equipped" << std::endl;
        return;
    }
    
    this->inventory[idx]->use(target);
}
