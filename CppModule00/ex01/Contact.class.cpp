/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuynguy <thuynguy@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 13:52:42 by thuynguy          #+#    #+#             */
/*   Updated: 2023/09/23 16:27:05 by thuynguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact( void ) {
    return;
}

Contact::~Contact( void ) {
    return;
}

std::string Contact::getFirstName( void ) const {
    return this->_firstName;
}

std::string Contact::getLastName( void ) const {
    return this->_lastName;
}

std::string Contact::getNickName( void ) const {
    return this->_nickName;
}

std::string Contact::getPhoneNumber( void ) const {
    return this->_phoneNumber;
}

std::string Contact::getDarkSecret( void ) const {
    return this->_darkSecret;
}

void    Contact::setFirstName( std::string s) {
    this->_firstName = s;

    return;
}

void    Contact::setLastName( std::string s) {
    this->_lastName = s;

    return;
}
void    Contact::setNickName( std::string s) {
    this->_nickName = s;

    return;
}
void    Contact::setPhoneNumber( std::string s) {
    this->_phoneNumber = s;

    return;
}
void    Contact::setDarkSecret( std::string s) {
    this->_darkSecret = s;

    return;
}
