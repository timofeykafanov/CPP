#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
    // Constructors & Destructor
    FragTrap();
    FragTrap(const std::string& name);
    FragTrap(const FragTrap& other);
    ~FragTrap();

    // Assignment operator
    FragTrap& operator=(const FragTrap& other);

    // Member functions
    void attack(const std::string& target);
    void highFivesGuys(void);
};

#endif // FRAGTRAP_HPP