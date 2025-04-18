#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery Creation", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("Shrubbery Creation", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target(other.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const std::string &ShrubberyCreationForm::getTarget() const {
    return target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!getIsSigned())
        throw NotSignedException();
    if (executor.getGrade() > getGradeRequiredToExecute())
        throw GradeTooLowException();
    
    std::string filename = target + "_shrubbery";
    std::ofstream outfile(filename.c_str());
    
    if (!outfile.is_open()) {
        std::cerr << "Error: Could not open file for writing" << std::endl;
        return;
    }
    
    outfile << "       _-_        " << std::endl;
    outfile << "    /~~   ~~\\    " << std::endl;
    outfile << " /~~         ~~\\ " << std::endl;
    outfile << "{               } " << std::endl;
    outfile << " \\  _-     -_  / " << std::endl;
    outfile << "   ~  \\\\ //  ~  " << std::endl;
    outfile << "_- -   | | _- _   " << std::endl;
    outfile << "  _ -  | |   -_   " << std::endl;
    outfile << "      // \\\\     " << std::endl;
    outfile << std::endl;
    outfile << "         *         " << std::endl;
    outfile << "        /|\\        " << std::endl;
    outfile << "       /*|O\\       " << std::endl;
    outfile << "      /*/|\\*\\     " << std::endl;
    outfile << "     /X/O|*\\X\\    " << std::endl;
    outfile << "    /*/X/|\\X\\*\\  " << std::endl;
    outfile << "   /O/*/X|*\\O\\X\\ " << std::endl;
    outfile << "  /*/O/X/|\\X\\O\\*\\" << std::endl;
    outfile << " /X/O/*/X|O\\X\\*\\O\\" << std::endl;
    outfile << "/O/X/*/O/|\\X\\*\\O\\X\\" << std::endl;
    outfile << "        |X|        " << std::endl;
    outfile << "        |X|        " << std::endl;
    
    outfile.close();
    std::cout << "Created shrubbery file: " << filename << std::endl;
}
