#include "Contact.hpp"

Contact::Contact()
{
    return;
}

Contact::~Contact()
{
    return;
}

std::string Contact::getFirstName() const
{
    return this->_firstName;
}

std::string Contact::getLastName() const
{
    return this->_lastName;
}

std::string Contact::getNickName() const
{
    return this->_nickName;
}

std::string Contact::getPhoneNumber() const
{
    return this->_phoneNumber;
}

std::string Contact::getDarkSecret() const
{
    return this->_darkSecret;
}

void Contact::setFirstName(std::string s)
{
    this->_firstName = s;

    return;
}

void Contact::setLastName(std::string s)
{
    this->_lastName = s;

    return;
}
void Contact::setNickName(std::string s)
{
    this->_nickName = s;

    return;
}
void Contact::setPhoneNumber(std::string s)
{
    this->_phoneNumber = s;

    return;
}
void Contact::setDarkSecret(std::string s)
{
    this->_darkSecret = s;

    return;
}

bool Contact::contactEmpty()
{
    if (this->_firstName.empty())
        return true;
    return false;
}
