#include "Dog.hpp"
#include <iostream>

Dog::Dog() : brain(new Brain()) {
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &other) : Animal(other) {
    std::cout << "Dog copy constructor called" << std::endl;
    this->brain = new Brain(*other.brain);
    this->type = other.type;
}

Dog &Dog::operator=(const Dog &other) {
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain;
}

void Dog::makeSound() const {
    std::cout << "Woof woof!" << std::endl;
}

Brain* Dog::getBrain() const {
    return this->brain;
}

void Dog::setBrainIdea(int index, const std::string &idea) {
    this->brain->setIdea(index, idea);
}

std::string Dog::getBrainIdea(int index) const {
    return this->brain->getIdea(index);
}
