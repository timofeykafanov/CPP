#include "Contact.hpp"
#include "PhoneBook.hpp"

#include <iostream>
#include <limits>

std::string getInput(const std::string& prompt, int *toExit) {
    std::string input;
    
    while (true) {
        std::cout << prompt;
        if (!std::getline(std::cin, input)) {
            std::cout << "\nExiting program! All your contacts are lost forever!" << std::endl;
            *toExit = 1;
            break;
        }
        else if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if (!input.empty()) {
            break;
        } else
            std::cout << "Field cannot be empty. Please try again." << std::endl;
    }

    return input;
}

int main() {
    PhoneBook phoneBook;
    std::string command;

    std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;

    while (true) {
        std::cout << "Enter a command (ADD, SEARCH or EXIT): ";

        if (!std::getline(std::cin, command)) {
            std::cout << "\nExiting program! All your contacts are lost forever!" << std::endl;
            break;
        }

        int toExit = 0;

        if (command == "ADD") {
            Contact newContact;

            newContact.setFirstName(getInput("Enter the first name: ", &toExit));
            if (toExit)
                break;
            newContact.setLastName(getInput("Enter the last name: ", &toExit));
            if (toExit)
                break;
            newContact.setNickname(getInput("Enter the nickname: ", &toExit));
            if (toExit)
                break;
            newContact.setPhoneNumber(getInput("Enter the phone number: ", &toExit));
            if (toExit)
                break;
            newContact.setDarkestSecret(getInput("Enter the darkest secret: ", &toExit));
            if (toExit)
                break;

            phoneBook.addContact(newContact);
            std::cout << "Contact added successfully!" << std::endl;
        } else if (command == "SEARCH") {
            phoneBook.searchContact(&toExit);
            if (toExit)
                break;
        }
        else if (command == "EXIT") {
            std::cout << "Goodbye! All your contacts are lost forever!" << std::endl;
            break;
        } else
            std::cout << "Invalid command." << std::endl;
    }

    return 0;
}
