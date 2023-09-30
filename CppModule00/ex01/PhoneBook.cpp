
#include "PhoneBook.hpp"

/* PUBLIC METHODS */

PhoneBook::PhoneBook() : _index(-1), _numContacts(0) {}

PhoneBook::~PhoneBook()
{
    _bibiByebye();
}

void PhoneBook::atYourService()
{
    std::string userInput;
    while (true)
    {
        userInput = _readInput("command:");
        if (userInput == "EXIT")
            break;
        else if (userInput == "ADD")
            _addContact();
        else if (userInput == "SEARCH")
            _searchContact();
        else
        {
            std::cout << "Please enter one of the three command: ";
            std::cout << "ADD, SEACH, EXIT" << '\n';
        }
    }
}

/* PRIVATE METHODS */

void PhoneBook::_trackIndex()
{
    _index++;
    if (_numContacts >= 8)
    {
        _index = 0;
        for (int i = 0; i < (_numContacts % 8); ++i)
            _index++;
    }
}

void PhoneBook::_bibiByebye()
{
    std::cout << "Exiting..." << '\n';
    std::cout << "Your saved contacts are now lost forever. ";
    std::cout << "Hope you are ok with that. If not, oopsie! Buh-bye!" << '\n';
    return;
}

void PhoneBook::_addContact()
{
    _trackIndex();
    std::string input;

    input = _readInput("first name. This field can't be left empty.");
    this->_contacts[_index].setFirstName(input);

    input = _readInput("last name. This field can't be left empty.");
    this->_contacts[_index].setLastName(input);

    input = _readInput("nick name. This field can't be left empty.");
    this->_contacts[_index].setNickName(input);

    input = _readInput("phone number. This field can't be left empty.");
    this->_contacts[_index].setPhoneNumber(input);

    input = _readInput("dark secret. This field can't be left empty.");
    this->_contacts[_index].setDarkSecret(input);

    _numContacts++;
    std::cout << "Contact saved successfully." << '\n';
}

std::string PhoneBook::_readInput(std::string const prompt)
{
    bool filledInfo = false;
    std::string raw_input;
    std::string trimmed_input;

    while (!filledInfo)
    {
        std::cout << "Enter your " << prompt << '\n';
        std::getline(std::cin, raw_input);
        if (std::cin.eof())
        {
            _bibiByebye();
            exit(0);
        }
        trimmed_input = _trimmed_input(raw_input);
        if (!trimmed_input.empty())
        {
            filledInfo = true;
        }
    }
    return trimmed_input;
}

std::string PhoneBook::_trimmed_input(std::string strToTrim) const
{
    std::string trimmed;
    size_t start = 0;
    size_t end = strToTrim.length();
    while (start < end && isspace(strToTrim[start]))
        start++;
    while (end > start && isspace(strToTrim[end - 1]))
        end--;
    trimmed = strToTrim.substr(start, end - start);
    for (std::string::iterator it = trimmed.begin(); it != trimmed.end(); ++it)
    {
        if (*it == '\t')
            *it = ' ';
    }
    return trimmed;
}

void PhoneBook::_searchContact()
{
    if (!_numContacts)
    {
        std::cout << "None saved contact to show. Try ADD contact first." << '\n';
        return;
    }
    _displayContactList();
    _searchByIndex();
}

void PhoneBook::_displayContactList()
{
    std::cout << "Current contact list to search from:" << '\n';
    std::cout << std::setw(10) << "Index"
              << "|"
              << std::setw(10) << "First name"
              << "|"
              << std::setw(10) << "Last name"
              << "|"
              << std::setw(10) << "Nickname" << '\n';

    for (int i = 0; i <= 7; ++i)
    {
        _displayContactEntry(i);
    }
}
void PhoneBook::_displayContactEntry(int const i)
{
    if (this->_contacts[i].contactEmpty())
        return;
    std::cout << std::setw(10) << i << "|"
              << std::setw(10) << _formatLongText(this->_contacts[i].getFirstName()) << "|"
              << std::setw(10) << _formatLongText(this->_contacts[i].getLastName()) << "|"
              << std::setw(10) << _formatLongText(this->_contacts[i].getNickName()) << '\n';
}

void PhoneBook::_displayContactInfo(int const index)
{
    if (this->_contacts[index].contactEmpty())
    {
        std::cout << "Error 404. Contact not found at given index." << '\n';
        return;
    }
    std::cout << "First name: " << this->_contacts[index].getFirstName() << '\n';
    std::cout << "Last name: " << this->_contacts[index].getLastName() << '\n';
    std::cout << "Nickname: " << this->_contacts[index].getNickName() << '\n';
    std::cout << "Phone number: " << this->_contacts[index].getPhoneNumber() << '\n';
    std::cout << "Dark secret: " << this->_contacts[index].getDarkSecret() << '\n';
}

std::string PhoneBook::_formatLongText(std::string text) const
{
    std::string formattedText = text;
    if (text.length() > COLUMN_WIDTH)
    {
        formattedText = text.substr(0, COLUMN_WIDTH - 1) + '.';
    }
    return formattedText;
}

void PhoneBook::_searchByIndex()
{
    int search_index;

    std::cout << "Enter the index of the contact you want to see: " << '\n';
    while (true)
    {
        if (!(std::cin >> search_index) || search_index < 0 || search_index > 7)
        {
            if (std::cin.eof())
            {
                _bibiByebye();
                exit(0);
            }
            std::cerr << "Invalid input. Please enter a valid index between 0 and 7." << '\n';
            std::cin.clear();
            while (std::cin.get() != '\n')
                ;
        }
        else
        {
            _displayContactInfo(search_index);
            while (std::cin.get() != '\n')
                ;
            break;
        }
    }
}