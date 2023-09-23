/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynguy <thuynguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:43:34 by thuynguy          #+#    #+#             */
/*   Updated: 2023/09/23 17:53:05 by thuynguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook( void ) : _numContacts(0) {
    return;
}

PhoneBook::~PhoneBook( void ) {
    return;
}

void    PhoneBook::addContact( void ) {
    _trackIndex();
    
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
}

