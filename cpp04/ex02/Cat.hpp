#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
private:
    Brain *brain;

public:
    Cat();
    Cat(const Cat &other);
    Cat &operator=(const Cat &other);
    virtual ~Cat();

    void makeSound() const;
    Brain* getBrain() const;
    void setBrainIdea(int index, const std::string &idea);
    std::string getBrainIdea(int index) const;
};

#endif
