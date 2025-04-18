#include "Bureaucrat.hpp"
#include "Form.hpp"
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

    try {
        std::cout << "Test 9: Creating a valid form" << std::endl;
        Form taxForm("Tax Return", 50, 25);
        std::cout << taxForm << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    try {
        std::cout << "Test 10: Creating a form with too high sign grade (0)" << std::endl;
        Form invalidForm("Invalid Form", 0, 25);
        std::cout << invalidForm << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    try {
        std::cout << "Test 11: Creating a form with too low execute grade (151)" << std::endl;
        Form invalidForm("Invalid Form", 50, 151);
        std::cout << invalidForm << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "Test 12: Successful signing" << std::endl;
        Bureaucrat highRank("High Rank", 20);
        Form easyForm("Easy Form", 25, 25);
        
        std::cout << "Before signing: " << easyForm << std::endl;
        highRank.signForm(easyForm);
        std::cout << "After signing: " << easyForm << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    try {
        std::cout << "Test 13: Failed signing due to low bureaucrat grade" << std::endl;
        Bureaucrat lowRank("Low Rank", 50);
        Form hardForm("Hard Form", 25, 25);
        
        std::cout << "Before signing: " << hardForm << std::endl;
        lowRank.signForm(hardForm);
        std::cout << "After signing: " << hardForm << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    try {
        std::cout << "Test 14: Form copy constructor and assignment" << std::endl;
        Form original("Original Form", 30, 40);
        Bureaucrat signer("Signer", 20);
        signer.signForm(original);
        
        Form copied(original);
        Form assigned;
        assigned = original;
        
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copied: " << copied << std::endl;
        std::cout << "Assigned: " << assigned << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
