#include <iostream>
#include <string>

int main() {
    std::string brain = "HI THIS IS BRAIN";

    std::string* stringPTR = &brain;

    std::string& stringREF = brain;

    std::cout << "Memory Addresses:" << std::endl;
    std::cout << "string variable: " << &brain << std::endl;
    std::cout << "stringPTR:       " << stringPTR << std::endl;
    std::cout << "stringREF:       " << &stringREF << std::endl;

    std::cout << "\nValues:" << std::endl;
    std::cout << "string variable: " << brain << std::endl;
    std::cout << "stringPTR:       " << *stringPTR << std::endl;
    std::cout << "stringREF:       " << stringREF << std::endl;

    return 0;
}