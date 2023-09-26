/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynguy <thuynguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:43:34 by thuynguy          #+#    #+#             */
/*   Updated: 2023/09/26 21:04:11 by thuynguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

/* PUBLIC METHODS */

PhoneBook::PhoneBook( void ) : _index(-1) {
    return;
}

PhoneBook::~PhoneBook( void ) {
    //std::cout << "Contact is saved." << std::endl;
    std::cout << "Your saved contacts are now lost forever. " << std::endl;
    std::cout << "Hope you are ok with that. If not, too bad." << std::endl;
    std::cout << "Thank you for using this crappy phonebook." << std::endl;
    return;
}

void    PhoneBook::atYourService( void ) {
    std::string userInput;
    while (1) {
        userInput = _readInput("command");
        if (userInput == "EXIT")
            break ;
        else if (userInput == "ADD")
            _addContact();
        else if (userInput == "SEARCH")
            _searchContact();
        else {
            std::cout << "Please enter one of the three command: ";
            std::cout << "ADD, SEACH, AND EXIT" << std::endl;
        }
    }
}

/* PRIVATE METHODS */
void    PhoneBook::_addContact( void ) {
    _trackIndex();
    std::string input;

    input = _readInput("first name");
    this->_contacts[_index].setFirstName(input);

    input = _readInput("last name");
    this->_contacts[_index].setLastName(input);

    input = _readInput("nick name");
    this->_contacts[_index].setNickName(input);

    input = _readInput("phone number");
    this->_contacts[_index].setPhoneNumber(input);

    input = _readInput("dark secret");
    this->_contacts[_index].setDarkSecret(input);
    
}

void    PhoneBook::_trackIndex( void ) {
    _index++;
    if (_index > 7) {
        _index = 0;
    }
}

// std::string PhoneBook::_readInput( std::string const prompt) {
//     std::string input;
    
//     std::cout << "Enter your " << prompt << ": " << std::endl;
//     std::getline (std::cin, input);
//     if (std::cin.eof()) {
//         std::cout << std::endl;
//         return std::string();
//     }
//     return input;
// }

std::string PhoneBook::_readInput( std::string const prompt ) {
    std::string input;
    bool        filledInfo = false;
    
    while (!filledInfo) {
        std::cout << "Enter your " << prompt << ": " << std::endl;
        std::getline (std::cin, input);
        if (std::cin.eof()) {
            input = "EXIT";
        }
        if (!input.empty()) {
            filledInfo = true;
        }
    }
    return input;
}

void    PhoneBook::_searchContact( void ) {
    _displayContactList();
    _searchByIndex();
}

void   PhoneBook::_displayContactList( void ) {
    std::cout << std::setw(10) << "Index" << " | "
                  << std::setw(10) << "First name" << " | "
                  << std::setw(10) << "Last name" << " | "
                  << std::setw(10) << "Nickname" << std::endl;
                  
    for (int i = 0; i <= _index; ++i) {
        std::cout << std::setw(10) << this->_contacts[i].getFirstName() << " | "
                  << std::setw(10) << this->_contacts[i].getLastName() << " | "
                  << std::setw(10) << this->_contacts[i].getNickName() << " | "
                  << std::setw(10) << this->_contacts[i].getPhoneNumber() << std::endl;
    }
}

void    PhoneBook::_displayContactInfo( const int index ) {
    std::cout << std::setw(10) << this->_contacts[index].getFirstName() << " | "
              << std::setw(10) << this->_contacts[index].getLastName() << " | "
              << std::setw(10) << this->_contacts[index].getNickName() << " | "
              << std::setw(10) << this->_contacts[index].getPhoneNumber() << std::endl;
}

void    PhoneBook::_searchByIndex( void ) {
    int index;

    std::cout << "Enter the index of the contact you want to see: ";
    if (!(std::cin >> index)) {
        std::cerr << "Invalid input. Please enter a valid index between 0 and 7." << std::endl;
        std::cin.clear();
        while (std::cin.get() != '\n');
        return;
    }
    if (index < 0 || index > 7)
        std::cerr << "Invalid index. Please enter a valid index between 0 and 7." << std::endl;
    else
        _displayContactInfo(index);
}