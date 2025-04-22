#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
    : name("Default Form"), isSigned(false), gradeRequiredToSign(150), gradeRequiredToExecute(150) {}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeRequiredToSign(gradeToSign), gradeRequiredToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &other)
    : name(other.name), isSigned(other.isSigned),
      gradeRequiredToSign(other.gradeRequiredToSign),
      gradeRequiredToExecute(other.gradeRequiredToExecute) {}

Form &Form::operator=(const Form &other) {
    if (this != &other) {
        this->isSigned = other.isSigned;
    }
    return *this;
}

Form::~Form() {}

const std::string &Form::getName() const {
    return name;
}

bool Form::getIsSigned() const {
    return isSigned;
}

int Form::getGradeRequiredToSign() const {
    return gradeRequiredToSign;
}

int Form::getGradeRequiredToExecute() const {
    return gradeRequiredToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() <= gradeRequiredToSign)
        isSigned = true;
    else
        throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high! The grade cannot be higher than 1.";
}

const char *Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low! The grade cannot be lower than 150.";
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
    os << "Form: " << form.getName() 
       << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
       << ", Grade Required to Sign: " << form.getGradeRequiredToSign()
       << ", Grade Required to Execute: " << form.getGradeRequiredToExecute();
    return os;
}
