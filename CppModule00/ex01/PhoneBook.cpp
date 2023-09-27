
#include "PhoneBook.hpp"

/* PUBLIC METHODS */

PhoneBook::PhoneBook() : _index(-1) {}

PhoneBook::~PhoneBook()
{
    // std::cout << "Contact is saved." << '\n';
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
    if (_index > 7)
    {
        _index = 0;
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
    return trimmed;
}

std::string PhoneBook::_readContactInfo(std::string const prompt)
{
    bool filledInfo = false;
    std::string input;

    while (!filledInfo)
    {
        std::cout << "Enter your " << prompt << '\n';
        std::getline(std::cin, input);
        if (std::cin.eof())
        {
            _bibiByebye();
            exit(0);
        }
        if (!input.empty())
        {
            filledInfo = true;
        }
    }
    return input;
}

void PhoneBook::_searchContact()
{
    if (_index == -1)
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
              << " | "
              << std::setw(10) << "First name"
              << " | "
              << std::setw(10) << "Last name"
              << " | "
              << std::setw(10) << "Nickname" << '\n';

    for (int i = 0; i <= _index; ++i)
    {
        std::cout << std::setw(10) << i << " | "
                  << std::setw(10) << _printLongText(this->_contacts[i].getFirstName()) << " | "
                  << std::setw(10) << _printLongText(this->_contacts[i].getLastName()) << " | "
                  << std::setw(10) << _printLongText(this->_contacts[i].getNickName()) << '\n';
    }
}

void PhoneBook::_displayContactInfo(int const index)
{
    std::cout << "First name: " << this->_contacts[index].getFirstName() << '\n';
    std::cout << "Last name: " << this->_contacts[index].getLastName() << '\n';
    std::cout << "Nickname: " << this->_contacts[index].getNickName() << '\n';
    std::cout << "Phone number: " << this->_contacts[index].getPhoneNumber() << '\n';
    std::cout << "Dark secret: " << this->_contacts[index].getDarkSecret() << '\n';
}

std::string PhoneBook::_printLongText(std::string text) const
{
    if (text.length() > 10)
    {
        text.resize(9);
        text += '.';
    }
    return text;
}

void PhoneBook::_searchByIndex()
{
    int search_index;

    std::cout << "Enter the index of the contact you want to see: " << '\n';
    while (true)
    {
        if (!(std::cin >> search_index))
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
        else if (search_index < 0 || search_index > _index)
        {
            std::cerr << "Index not found. Your phonebook has ";
            std::cerr << _index + 1;
            std::cerr << " contacts. Please enter a valid index accordingly." << '\n';
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