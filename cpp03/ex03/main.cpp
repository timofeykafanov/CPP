#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>
#include <sstream>

int main() {
    std::cout << "===== ClapTrap Tests =====" << std::endl;
    
    ClapTrap clap1("CL4P-TP");
    
    clap1.attack("Enemy Robot");
    
    clap1.takeDamage(5);
    
    clap1.beRepaired(3);
    
    std::cout << "\n===== ScavTrap Tests =====" << std::endl;
    
    ScavTrap scav1("SC4V-TP");
    
    scav1.attack("Enemy Bandit");
    
    scav1.takeDamage(30);
    
    scav1.beRepaired(15);
    
    scav1.guardGate();

    std::cout << "\n===== FragTrap Tests =====" << std::endl;
    
    FragTrap frag1("FR4G-TP");
    
    frag1.attack("Enemy Psycho");
    
    frag1.takeDamage(40);
    
    frag1.beRepaired(20);
    
    frag1.highFivesGuys();

    std::cout << "\n===== DiamondTrap Tests =====" << std::endl;
    
    DiamondTrap diamond1("DI4M-TP");
    
    diamond1.attack("Super Enemy");
    
    diamond1.takeDamage(50);
    
    diamond1.beRepaired(25);
    
    diamond1.guardGate();
    diamond1.highFivesGuys();
    
    diamond1.whoAmI();
    
    std::cout << "\n===== Constructor/Destructor Chaining Tests =====" << std::endl;
    
    {
        std::cout << "Creating a new ScavTrap..." << std::endl;
        ScavTrap scav2("Chain-TP");
        std::cout << "ScavTrap created, leaving scope..." << std::endl;
    }

    {
        std::cout << "\nCreating FragTrap..." << std::endl;
        FragTrap frag2("Chain-FR4G");
        std::cout << "FragTrap created, leaving scope..." << std::endl;
    }

    {
        std::cout << "\nCreating DiamondTrap..." << std::endl;
        DiamondTrap diamond2("Chain-DI4M");
        std::cout << "DiamondTrap created, leaving scope..." << std::endl;
    }
    
    std::cout << "\n===== Energy Depletion Test (ScavTrap) =====" << std::endl;
    
    for (int i = 0; i < 10; i++) {
        std::ostringstream oss;
        oss << "Target " << i;
        scav1.attack(oss.str());
    }

    std::cout << "\n===== Polymorphism Test =====" << std::endl;
    
    ClapTrap* polyClap = new ClapTrap("Poly-CL4P");
    ClapTrap* polyScav = new ScavTrap("Poly-SC4V");
    ClapTrap* polyFrag = new FragTrap("Poly-FR4G");
    
    polyClap->attack("Target");
    polyScav->attack("Target");
    polyFrag->attack("Target");
    
    delete polyClap;
    delete polyScav;
    delete polyFrag;
    
    return 0;
}