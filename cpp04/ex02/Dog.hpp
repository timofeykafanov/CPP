#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
private:
    Brain *brain;

public:
    Dog();
    Dog(const Dog &other);
    Dog &operator=(const Dog &other);
    virtual ~Dog();

    void makeSound() const;
    Brain* getBrain() const;
    void setBrainIdea(int index, const std::string &idea);
    std::string getBrainIdea(int index) const;
};

#endif
