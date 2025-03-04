#include "Zombie.hpp"
#include <iostream>

int main() {
    std::cout << "Heap Zombie:" << std::endl;
    Zombie* heapZombie = newZombie("Heap Zombie");
    heapZombie->announce();
    delete heapZombie;

    std::cout << "\nStack Zombie:" << std::endl;
    randomChump("Stack Zombie");

    return 0;
}