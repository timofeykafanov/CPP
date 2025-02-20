#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int index;
    int count;

public:
    PhoneBook() : index(0), count(0) {}

    void addContact() {
        Contact newContact;
        newContact.setContact();
        if (!newContactIsEmpty(newContact)) {
            contacts[index] = newContact;
            std::cout << "Contact added at position " << index + 1 << "\n";
            index = (index + 1) % 8;
            if (count < 8) count++;
        }
    }

    void searchContacts() const {
        if (count == 0) {
            std::cout << "Phonebook is empty.\n";
            return;
        }

        std::cout << std::setw(10) << "Index" << "|"
                  << std::setw(10) << "First Name" << "|"
                  << std::setw(10) << "Last Name" << "|"
                  << std::setw(10) << "Nickname" << "|\n";
        std::cout << "---------------------------------------------\n";

        for (int i = 0; i < count; i++) {
            contacts[i].displayShort(i + 1);
        }

        int selectedIndex;
        std::cout << "Enter the contact index to view details: ";
        std::cin >> selectedIndex;

        if (std::cin.fail() || selectedIndex < 1 || selectedIndex > count) {
            std::cout << "Invalid index.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        contacts[selectedIndex - 1].displayFull();
    }

private:
    bool newContactIsEmpty(const Contact &contact) {
        std::ostringstream oss;
        std::ostream &os = oss;
        os << &contact;
        return oss.str().empty();
    }
};