#include <iostream>
#include <string>
#include <iomanip>

class Contact {
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;

public:
    void setContact() {
        std::cout << "Enter First Name: ";
        std::getline(std::cin, firstName);
        std::cout << "Enter Last Name: ";
        std::getline(std::cin, lastName);
        std::cout << "Enter Nickname: ";
        std::getline(std::cin, nickname);
        std::cout << "Enter Phone Number: ";
        std::getline(std::cin, phoneNumber);
        std::cout << "Enter Darkest Secret: ";
        std::getline(std::cin, darkestSecret);

        if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty()) {
            std::cout << "Error: No fields can be empty. Contact was not added.\n";
        }
    }

    void displayShort(int index) const {
        std::cout << std::setw(10) << index << "|"
                  << std::setw(10) << formatField(firstName) << "|"
                  << std::setw(10) << formatField(lastName) << "|"
                  << std::setw(10) << formatField(nickname) << "|\n";
    }

    void displayFull() const {
        std::cout << "First Name: " << firstName << "\n";
        std::cout << "Last Name: " << lastName << "\n";
        std::cout << "Nickname: " << nickname << "\n";
        std::cout << "Phone Number: " << phoneNumber << "\n";
        std::cout << "Darkest Secret: " << darkestSecret << "\n";
    }

private:
    std::string formatField(std::string field) const {
        return field.length() > 10 ? field.substr(0, 9) + "." : field;
    }
};