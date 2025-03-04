#include "Zombie.hpp"
#include <iostream>

int main() {
    int sizes[] = {3, 5, 0};
    
    for (size_t i = 0; i < sizeof(sizes)/sizeof(sizes[0]); i++) {
        int N = sizes[i];
        
        std::cout << "\nCreating a horde of " << N << " zombies:" << std::endl;
        
        if (N > 0) {
            Zombie* horde = zombieHorde(N, "Brain Muncher");
            
            for (int j = 0; j < N; j++) {
                horde[j].announce();
            }
            
            delete[] horde;
        }
        else {
            std::cout << "Cannot create a horde of 0 or less zombies." << std::endl;
        }
    }
    
    return 0;
}