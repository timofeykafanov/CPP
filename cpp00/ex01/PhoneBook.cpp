#include "PhoneBook.hpp"

#include <iostream>
#include <iomanip>
#include <string>

PhoneBook::PhoneBook() :
    oldestContactIndex(0),
    contactCount(0)
{}

void PhoneBook::addContact(const Contact& contact) {
    if (contactCount < 8) {
        contacts[contactCount] = contact;
        contactCount++;
    } else {
        contacts[oldestContactIndex] = contact;
        oldestContactIndex = (oldestContactIndex + 1) % 8;
    }
}

std::string PhoneBook::truncateString(const std::string& str) const {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    }
    return str;
}

void PhoneBook::displayAllContacts() const {
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First name" << "|";
    std::cout << std::setw(10) << "Last name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;

    for(int i = 0; i < contactCount; i++) {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << truncateString(contacts[i].getFirstName()) << "|";
        std::cout << std::setw(10) << truncateString(contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << truncateString(contacts[i].getNickname()) << std::endl;
    }
}

void PhoneBook::searchContact(int *toExit) const {
    if (contactCount == 0) {
        std::cout << "No contacts to search for." << std::endl;
        return;
    }

    displayAllContacts();

    std::string input;
    int index;

    std::cout << "Enter the index of the contact you want to see: ";
    
    if (!std::getline(std::cin, input)) {
        std::cout << "\nExiting program! All your contacts are lost forever!" << std::endl;
        *toExit = 1;
        return;
    }

    index = input[0] - '0';

    if (input.length() != 1 || index < 0 || index >= contactCount) {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    std::cout << "First name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << contacts[index].getDarkestSecret() << std::endl;
}
