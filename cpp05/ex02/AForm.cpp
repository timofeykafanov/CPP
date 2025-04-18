#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    : name("Default AForm"), isSigned(false), gradeRequiredToSign(150), gradeRequiredToExecute(150) {}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeRequiredToSign(gradeToSign), gradeRequiredToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : name(other.name), isSigned(other.isSigned),
      gradeRequiredToSign(other.gradeRequiredToSign),
      gradeRequiredToExecute(other.gradeRequiredToExecute) {}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other) {
        this->isSigned = other.isSigned;
    }
    return *this;
}

AForm::~AForm() {}

const std::string &AForm::getName() const {
    return name;
}

bool AForm::getIsSigned() const {
    return isSigned;
}

int AForm::getGradeRequiredToSign() const {
    return gradeRequiredToSign;
}

int AForm::getGradeRequiredToExecute() const {
    return gradeRequiredToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() <= gradeRequiredToSign)
        isSigned = true;
    else
        throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw() {
    return "AForm grade is too high! The grade cannot be higher than 1.";
}

const char *AForm::GradeTooLowException::what() const throw() {
    return "AForm grade is too low! The grade cannot be lower than 150.";
}

const char *AForm::NotSignedException::what() const throw() {
    return "Form is not signed! Cannot execute unsigned form.";
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
    os << "AForm: " << form.getName() 
       << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
       << ", Grade Required to Sign: " << form.getGradeRequiredToSign()
       << ", Grade Required to Execute: " << form.getGradeRequiredToExecute();
    return os;
}
