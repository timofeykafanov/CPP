#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) {
    static bool first = true;
    if (first) {
        std::srand(std::time(NULL));
        first = false;
    }
    
    int random = std::rand() % 3;
    
    switch (random) {
        case 0:
            std::cout << "Generated an A object" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated a B object" << std::endl;
            return new B();
        case 2:
            std::cout << "Generated a C object" << std::endl;
            return new C();
        default:
            return NULL;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "Type identified by pointer: A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Type identified by pointer: B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Type identified by pointer: C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "Type identified by reference: A" << std::endl;
        return;
    } catch (...) {}
    
    try {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "Type identified by reference: B" << std::endl;
        return;
    } catch (...) {}
    
    try {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "Type identified by reference: C" << std::endl;
        return;
    } catch (...) {
        std::cout << "Unknown type" << std::endl;
    }
}

int main() {
    for (int i = 0; i < 5; i++) {
        std::cout << "\n----- Test " << i + 1 << " -----" << std::endl;
        
        Base* obj = generate();
        
        identify(obj);
        identify(*obj);
        
        delete obj;
    }
    
    return 0;
}
