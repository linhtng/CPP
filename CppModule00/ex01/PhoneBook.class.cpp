/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynguy <thuynguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:43:34 by thuynguy          #+#    #+#             */
/*   Updated: 2023/09/25 17:52:02 by thuynguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook( void ) : _index(-1) {
    return;
}

PhoneBook::~PhoneBook( void ) {
    std::cout << "Contact saved: " << std::endl;
    std::cout << this->_contacts[_index].getFirstName() << std::endl;
    std::cout << this->_contacts[_index].getLastName() << std::endl;
    std::cout << this->_contacts[_index].getNickName() << std::endl;
    std::cout << this->_contacts[_index].getPhoneNumber() << std::endl;
    std::cout << this->_contacts[_index].getDarkSecret() << std::endl;
    return;
}

void    PhoneBook::addContact( void ) {
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

std::string PhoneBook::_readInput( std::string const prompt) {
    std::string input;
    
    std::cout << "Enter your " << prompt << ": " << std::endl;
    std::getline (std::cin, input);
    if (std::cin.eof()) {
        std::cout << std::endl;
        return std::string();
    }
    return input;
}

