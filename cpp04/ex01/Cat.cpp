#include "Cat.hpp"
#include <iostream>

Cat::Cat() : brain(new Brain()) {
    std::cout << "Cat default constructor called" << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
    this->brain = new Brain(*other.brain);
    this->type = other.type;
}

Cat &Cat::operator=(const Cat &other) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete this->brain;
}

void Cat::makeSound() const {
    std::cout << "Meow meow!" << std::endl;
}

Brain* Cat::getBrain() const {
    return this->brain;
}

void Cat::setBrainIdea(int index, const std::string &idea) {
    this->brain->setIdea(index, idea);
}

std::string Cat::getBrainIdea(int index) const {
    return this->brain->getIdea(index);
}
