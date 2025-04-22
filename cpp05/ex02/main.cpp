#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

void testShrubberyCreationForm() {
    std::cout << "\n=== Testing ShrubberyCreationForm ===\n" << std::endl;
    
    try {
        ShrubberyCreationForm form("garden");
        Bureaucrat highRank("HighRank", 100);
        Bureaucrat midRank("MidRank", 140);
        Bureaucrat lowRank("LowRank", 150);
        
        std::cout << form << std::endl;
        
        std::cout << "\nTesting signing:" << std::endl;
        lowRank.signForm(form); // Should fail
        midRank.signForm(form);
        
        std::cout << "\nTesting execution:" << std::endl;
        midRank.executeForm(form); // Should fail
        highRank.executeForm(form);
        
    } catch (std::exception &e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
}

void testRobotomyRequestForm() {
    std::cout << "\n=== Testing RobotomyRequestForm ===\n" << std::endl;
    
    try {
        RobotomyRequestForm form("Bender");
        Bureaucrat highRank("HighRank", 20);
        Bureaucrat midRank("MidRank", 70);
        Bureaucrat lowRank("LowRank", 100);
        
        std::cout << form << std::endl;
        
        std::cout << "\nTesting signing:" << std::endl;
        lowRank.signForm(form);  // Should fail
        midRank.signForm(form);
        
        std::cout << "\nTesting execution:" << std::endl;
        midRank.executeForm(form); // Should fail
        highRank.executeForm(form);
        highRank.executeForm(form);
        
    } catch (std::exception &e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
}

void testPresidentialPardonForm() {
    std::cout << "\n=== Testing PresidentialPardonForm ===\n" << std::endl;
    
    try {
        PresidentialPardonForm form("Arthur Dent");
        Bureaucrat highRank("HighRank", 1);
        Bureaucrat midRank("MidRank", 20);
        Bureaucrat lowRank("LowRank", 30);
        
        std::cout << form << std::endl;
        
        std::cout << "\nTesting signing:" << std::endl;
        lowRank.signForm(form); // Should fail
        midRank.signForm(form);
        
        std::cout << "\nTesting execution:" << std::endl;
        midRank.executeForm(form); // Should fail
        highRank.executeForm(form);
        
    } catch (std::exception &e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
}

void testUnsignedFormExecution() {
    std::cout << "\n=== Testing Unsigned Form Execution ===\n" << std::endl;
    
    try {
        ShrubberyCreationForm form("home");
        Bureaucrat bureaucrat("Bureaucrat", 1);
        
        std::cout << "Attempting to execute unsigned form:" << std::endl;
        bureaucrat.executeForm(form); // Should fail
        
    } catch (std::exception &e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
}

int main() {
    testShrubberyCreationForm();
    testRobotomyRequestForm();
    testPresidentialPardonForm();
    testUnsignedFormExecution();
    
    return 0;
}
