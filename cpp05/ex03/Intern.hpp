#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <string>

class Intern {
private:
    typedef AForm* (Intern::*FormCreator)(const std::string&) const;
    
    AForm* createShrubberyCreationForm(const std::string& target) const;
    AForm* createRobotomyRequestForm(const std::string& target) const;
    AForm* createPresidentialPardonForm(const std::string& target) const;
    
    struct FormType {
        std::string name;
        FormCreator creator;
    };

public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();
    
    AForm* makeForm(const std::string& formName, const std::string& target) const;
    
    class UnknownFormException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

#endif
