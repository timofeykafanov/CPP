#include "Harl.hpp"
#include <iostream>

int main() {
    Harl harl;

    std::cout << "Testing DEBUG complaint:" << std::endl;
    harl.complain("DEBUG");
    
    std::cout << "\nTesting INFO complaint:" << std::endl;
    harl.complain("INFO");
    
    std::cout << "\nTesting WARNING complaint:" << std::endl;
    harl.complain("WARNING");
    
    std::cout << "\nTesting ERROR complaint:" << std::endl;
    harl.complain("ERROR");
    
    std::cout << "\nTesting invalid complaint:" << std::endl;
    harl.complain("INVALID");

    return 0;
}