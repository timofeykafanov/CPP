#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

void testInternWithValidForms() {
    std::cout << "\n=== Testing Intern with Valid Forms ===\n" << std::endl;
    
    try {
        Intern someRandomIntern;
        Bureaucrat boss("Big Boss", 1);
        
        std::cout << "Creating ShrubberyCreationForm:" << std::endl;
        AForm* scf = someRandomIntern.makeForm("shrubbery creation", "garden");
        std::cout << *scf << std::endl;
        boss.signForm(*scf);
        boss.executeForm(*scf);
        delete scf;
        
        std::cout << "\nCreating RobotomyRequestForm:" << std::endl;
        AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << *rrf << std::endl;
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
        
        std::cout << "\nCreating PresidentialPardonForm:" << std::endl;
        AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
        std::cout << *ppf << std::endl;
        boss.signForm(*ppf);
        boss.executeForm(*ppf);
        delete ppf;
        
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void testInternWithInvalidForm() {
    std::cout << "\n=== Testing Intern with Invalid Form ===\n" << std::endl;
    
    try {
        Intern someRandomIntern;
        
        std::cout << "Creating NonexistentForm:" << std::endl;
        AForm* invalidForm = someRandomIntern.makeForm("coffee request", "Office");
        std::cout << *invalidForm << std::endl;
        delete invalidForm;
        
    } catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

void testInternWithCaseInsensitivity() {
    std::cout << "\n=== Testing Intern with Case-Insensitive Form Names ===\n" << std::endl;
    
    try {
        Intern someRandomIntern;
        Bureaucrat manager("Manager", 20);
        
        std::cout << "Creating form with mixed case:" << std::endl;
        AForm* mixedCase = someRandomIntern.makeForm("RoBoToMy ReQuEsT", "R2D2");
        std::cout << *mixedCase << std::endl;
        manager.signForm(*mixedCase);
        manager.executeForm(*mixedCase);
        delete mixedCase;
        
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void demonstrateExampleCode() {
    std::cout << "\n=== Demonstrating Example Code ===\n" << std::endl;
    
    try {
        Intern someRandomIntern;
        Bureaucrat boss("Boss", 1);
        
        AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << *rrf << std::endl;
        boss.signForm(*rrf);
        boss.executeForm(*rrf);
        delete rrf;
        
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

int main() {
    testInternWithValidForms();
    testInternWithInvalidForm();
    testInternWithCaseInsensitivity();
    demonstrateExampleCode();
    
    return 0;
}
