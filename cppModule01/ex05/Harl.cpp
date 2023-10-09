#include "Harl.hpp"

/* Public */

Harl::Harl() {}
Harl::~Harl() {}

void Harl::complain(std::string level)
{
    void (Harl::*func)() = NULL;

    switch (level[0])
    {
    case 'D':
        func = &Harl::debug;
        break;
    case 'I':
        func = &Harl::info;
        break;
    case 'W':
        func = &Harl::warning;
        break;
    case 'E':
        func = &Harl::error;
        break;
    default:
        func = &Harl::threaten;
        break;
    }
    (this->*func)();
}

/* Private */

void Harl::debug()
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. ";
    std::cout << "I really do!\n";
}

void Harl::info()
{
    std::cout << "I cannot believe adding extra bacon costs more money. ";
    std::cout << "You didn't put enough bacon in my burger! ";
    std::cout << "If you did, I wouldn't be asking for more!\n";
}

void Harl::warning()
{
    std::cout << "I think I deserve to have some extra bacon for free. ";
    std::cout << "I've been coming for years whereas you started working here since last month.\n";
}

void Harl::error()
{
    std::cout << "This is unacceptable! ";
    std::cout << "I want to speak to the manager now.\n";
}

void Harl::threaten()
{
    std::cout << "I'm about to end your whole career.\n";
}