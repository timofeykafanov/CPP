#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>
#include <sstream>

int main() {
    std::cout << "===== Basic Test from Subject =====" << std::endl;
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    
    delete dog;
    delete cat;
    
    std::cout << "\n===== Array of Animals Test =====" << std::endl;
    const int arraySize = 10;
    Animal* animals[arraySize];
    
    for (int k = 0; k < arraySize; k++) {
        if (k < arraySize / 2) {
            animals[k] = new Dog();
            std::ostringstream oss;
            oss << k;
            std::string str = oss.str();
            static_cast<Dog*>(animals[k])->setBrainIdea(0, "Dog thought " + str);
        } else {
            animals[k] = new Cat();
            std::ostringstream oss;
            oss << k;
            std::string str = oss.str();
            static_cast<Cat*>(animals[k])->setBrainIdea(0, "Cat thought " + str);
        }
    }
    
    for (int k = 0; k < arraySize; k++) {
        std::cout << "Animal " << k << " is a " << animals[k]->getType() << std::endl;
        animals[k]->makeSound();
        
        if (animals[k]->getType() == "Dog") {
            std::cout << "  Brain idea: " << static_cast<Dog*>(animals[k])->getBrainIdea(0) << std::endl;
        } else if (animals[k]->getType() == "Cat") {
            std::cout << "  Brain idea: " << static_cast<Cat*>(animals[k])->getBrainIdea(0) << std::endl;
        }
    }
    
    std::cout << "\n===== Deleting Animals =====" << std::endl;
    for (int k = 0; k < arraySize; k++) {
        delete animals[k];
    }
    
    std::cout << "\n===== Testing Deep Copy =====" << std::endl;
    Dog *originalDog = new Dog();
    originalDog->setBrainIdea(0, "I love bones!");
    originalDog->setBrainIdea(1, "I want to chase cats!");
    
    Dog *copiedDog = new Dog(*originalDog);
    
    originalDog->setBrainIdea(0, "Changed idea in original");
    
    std::cout << "Original dog idea[0]: " << originalDog->getBrainIdea(0) << std::endl;
    std::cout << "Copied dog idea[0]: " << copiedDog->getBrainIdea(0) << std::endl;
    std::cout << "Original dog idea[1]: " << originalDog->getBrainIdea(1) << std::endl;
    std::cout << "Copied dog idea[1]: " << copiedDog->getBrainIdea(1) << std::endl;
    
    Dog assignedDog;
    assignedDog = *originalDog;
    
    originalDog->setBrainIdea(1, "Another changed idea");
    
    std::cout << "Original dog idea[1] after change: " << originalDog->getBrainIdea(1) << std::endl;
    std::cout << "Assigned dog idea[1]: " << assignedDog.getBrainIdea(1) << std::endl;
    
    delete originalDog;
    delete copiedDog;
    
    std::cout << "\n===== Additional Tests =====" << std::endl;
    
    {
        std::cout << "\nTesting Dog constructors and operators:" << std::endl;
        Dog dog1;
        dog1.setBrainIdea(0, "Original dog idea");
        
        Dog dog2 = dog1;
        Dog dog3;
        dog3 = dog1;
        
        std::cout << "dog1 idea: " << dog1.getBrainIdea(0) << std::endl;
        std::cout << "dog2 idea: " << dog2.getBrainIdea(0) << std::endl;
        std::cout << "dog3 idea: " << dog3.getBrainIdea(0) << std::endl;
        
        dog1.setBrainIdea(0, "Modified dog idea");
        std::cout << "After modification:" << std::endl;
        std::cout << "dog1 idea: " << dog1.getBrainIdea(0) << std::endl;
        std::cout << "dog2 idea: " << dog2.getBrainIdea(0) << std::endl;
        std::cout << "dog3 idea: " << dog3.getBrainIdea(0) << std::endl;
    }
    
    {
        std::cout << "\nTesting Cat constructors and operators:" << std::endl;
        Cat cat1;
        cat1.setBrainIdea(0, "Original cat idea");
        
        Cat cat2 = cat1;
        Cat cat3;
        cat3 = cat1;
        
        std::cout << "cat1 idea: " << cat1.getBrainIdea(0) << std::endl;
        std::cout << "cat2 idea: " << cat2.getBrainIdea(0) << std::endl;
        std::cout << "cat3 idea: " << cat3.getBrainIdea(0) << std::endl;
        
        cat1.setBrainIdea(0, "Modified cat idea");
        std::cout << "After modification:" << std::endl;
        std::cout << "cat1 idea: " << cat1.getBrainIdea(0) << std::endl;
        std::cout << "cat2 idea: " << cat2.getBrainIdea(0) << std::endl;
        std::cout << "cat3 idea: " << cat3.getBrainIdea(0) << std::endl;
    }
    
    return 0;
}
