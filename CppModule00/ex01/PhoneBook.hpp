
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iomanip>
#include "Contact.hpp"

#define COLUMN_WIDTH 10

class PhoneBook
{

public:
    PhoneBook();
    ~PhoneBook();

    void atYourService();

private:
    Contact _contacts[8];
    int _index;
    int _numContacts;

    std::string _readInput(std::string const prompt);

    void _addContact();
    void _searchContact();
    void _trackIndex();
    void _displayContactList();
    void _displayContactEntry(int const i);
    void _searchByIndex();
    void _displayContactInfo(int const index);
    void _bibiByebye();
    std::string _trimmed_input(std::string strToTrim) const;
    std::string _formatLongText(std::string text) const;
};

#endif