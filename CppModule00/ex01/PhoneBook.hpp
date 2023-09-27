
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{

public:
    PhoneBook();
    ~PhoneBook();

    void atYourService();

private:
    Contact _contacts[8];
    int _index;

    std::string _readInput(std::string const prompt);
    std::string _readContactInfo(std::string const prompt);

    void _addContact();
    void _searchContact();
    void _trackIndex();
    void _displayContactList();
    void _searchByIndex();
    void _displayContactInfo(int const index);
    void _bibiByebye();
    std::string _trimmed_input(std::string strToTrim) const;
    std::string _printLongText(std::string text) const;
};

#endif