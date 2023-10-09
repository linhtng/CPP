#include "Harl.hpp"

/* Public */

Harl::Harl() {}
Harl::~Harl() {}

void Harl::complain(std::string level)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*func[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    for (int i = 0; i < 4; ++i)
    {
        if (level == levels[i])
            (this->*func[i])();
    }
}

/* Private */

void Harl::debug()
{
    std::cout << "[ DEBUG ]\n";
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. ";
    std::cout << "I really do!\n";
    std::cout << '\n';
}

void Harl::info()
{
    std::cout << "[ INFO ]\n";
    std::cout << "I cannot believe adding extra bacon costs more money. ";
    std::cout << "You didn't put enough bacon in my burger! ";
    std::cout << "If you did, I wouldn't be asking for more!\n";
    std::cout << '\n';
}

void Harl::warning()
{
    std::cout << "[ WARNING ]\n";
    std::cout << "I think I deserve to have some extra bacon for free. ";
    std::cout << "I've been coming for years whereas you started working here since last month.\n";
    std::cout << '\n';
}

void Harl::error()
{
    std::cout << "[ ERROR ]\n";
    std::cout << "This is unacceptable! ";
    std::cout << "I want to speak to the manager now.\n";
    std::cout << '\n';
}