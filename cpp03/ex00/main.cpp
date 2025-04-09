#include "ClapTrap.hpp"
#include <sstream>

int main() {
    ClapTrap clap1("CL4P-TP");
    
    clap1.attack("Enemy Robot");
    
    clap1.takeDamage(5);
    
    clap1.beRepaired(3);
    
    clap1.takeDamage(7);
    
    clap1.attack("Enemy Robot");
    
    clap1.beRepaired(9);

    ClapTrap clap2(clap1);
    
    for (int i = 0; i < 6; i++) {
        std::ostringstream oss;
        oss << "Target " << i;
        clap2.attack(oss.str());
    }
    
    clap2.attack("Final Target");
    
    clap2.beRepaired(5);
    
    return 0;
}
