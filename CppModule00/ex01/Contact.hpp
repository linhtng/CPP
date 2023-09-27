#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>
#include <string>

#define FAILURE 1
#define SUCCESS 0

class Contact
{

public:
    Contact();
    ~Contact();

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickName() const;
    std::string getPhoneNumber() const;
    std::string getDarkSecret() const;
    void setFirstName(std::string s);
    void setLastName(std::string s);
    void setNickName(std::string s);
    void setPhoneNumber(std::string s);
    void setDarkSecret(std::string s);

private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickName;
    std::string _phoneNumber;
    std::string _darkSecret;
};

#endif