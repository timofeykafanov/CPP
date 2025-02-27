#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
    private:
        Contact contacts[8];
        int oldestContactIndex;
        int contactCount;

        std::string truncateString(const std::string& str) const;

    public:
        PhoneBook();

        void addContact(const Contact& contact);
        void displayAllContacts() const;
        void searchContact(int *) const;
};

#endif