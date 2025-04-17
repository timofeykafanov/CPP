#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
    std::cout << "===== Testing with proper polymorphism =====" << std::endl;
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    
    cat->makeSound();
    dog->makeSound();
    meta->makeSound();

    delete meta;
    delete dog;
    delete cat;

    std::cout << "\n===== Testing with wrong polymorphism =====" << std::endl;
    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << " " << std::endl;
    
    wrongCat->makeSound();
    wrongAnimal->makeSound();

    delete wrongAnimal;
    delete wrongCat;

    std::cout << "\n===== Additional tests =====" << std::endl;
    
    std::cout << "\nDirectly instantiated objects:" << std::endl;
    Animal directAnimal;
    Dog directDog;
    Cat directCat;
    
    directAnimal.makeSound();
    directDog.makeSound();
    directCat.makeSound();
    
    std::cout << "\nCopy construction:" << std::endl;
    Animal copyAnimal = directAnimal;
    Dog copyDog = directDog;
    
    copyAnimal.makeSound();
    copyDog.makeSound();

    return 0;
}
