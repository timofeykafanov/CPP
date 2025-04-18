#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        std::cout << "Test 1: Creating a valid bureaucrat" << std::endl;
        Bureaucrat bob("Bob", 75);
        std::cout << bob << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    try {
        std::cout << "Test 2: Creating a bureaucrat with too high grade (0)" << std::endl;
        Bureaucrat alice("Alice", 0);
        std::cout << alice << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    try {
        std::cout << "Test 3: Creating a bureaucrat with too low grade (151)" << std::endl;
        Bureaucrat charlie("Charlie", 151);
        std::cout << charlie << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    try {
        std::cout << "Test 4: Incrementing grade" << std::endl;
        Bureaucrat dave("Dave", 10);
        std::cout << "Before increment: " << dave << std::endl;
        dave.incrementGrade();
        std::cout << "After increment: " << dave << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    try {
        std::cout << "Test 5: Decrementing grade" << std::endl;
        Bureaucrat eve("Eve", 140);
        std::cout << "Before decrement: " << eve << std::endl;
        eve.decrementGrade();
        std::cout << "After decrement: " << eve << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    try {
        std::cout << "Test 6: Incrementing grade to invalid value" << std::endl;
        Bureaucrat frank("Frank", 1);
        std::cout << "Before increment: " << frank << std::endl;
        frank.incrementGrade(); // This should throw an exception
        std::cout << "After increment: " << frank << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    try {
        std::cout << "Test 7: Decrementing grade to invalid value" << std::endl;
        Bureaucrat grace("Grace", 150);
        std::cout << "Before decrement: " << grace << std::endl;
        grace.decrementGrade(); // This should throw an exception
        std::cout << "After decrement: " << grace << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    try {
        std::cout << "Test 8: Testing copy constructor and assignment operator" << std::endl;
        Bureaucrat original("Original", 42);
        Bureaucrat copy(original);
        Bureaucrat assigned;
        assigned = original;

        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy: " << copy << std::endl;
        std::cout << "Assigned: " << assigned << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
