#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {
    private:
        std::string name;
    
    public:
        Zombie(void);
        Zombie(std::string zombieName);
        ~Zombie(void);

        void setName(std::string zombieName);
        void announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif // ZOMBIE_HPP