#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <algorithm>

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::createShrubberyCreationForm(const std::string& target) const {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) const {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) const {
    return new PresidentialPardonForm(target);
}

const char* Intern::UnknownFormException::what() const throw() {
    return "Error: Unknown form type requested";
}

std::string toLower(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    const FormType formTypes[] = {
        {"shrubbery creation", &Intern::createShrubberyCreationForm},
        {"robotomy request", &Intern::createRobotomyRequestForm},
        {"presidential pardon", &Intern::createPresidentialPardonForm}
    };
    const int numFormTypes = sizeof(formTypes) / sizeof(FormType);
    
    std::string formNameLower = toLower(formName);
    
    for (int i = 0; i < numFormTypes; i++) {
        if (toLower(formTypes[i].name) == formNameLower) {
            AForm* form = (this->*formTypes[i].creator)(target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }
    
    std::cerr << "Intern cannot create form: " << formName << " (unknown type)" << std::endl;
    throw UnknownFormException();
}
