#include "Harl.hpp"
#define DEFAULT_LV "[ Probably complaining about insignificant problems ]"

void harlFilter(std::string level)
{
    Harl Harl;
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i;
    for (i = 0; i < 4; ++i)
    {
        if (level == levels[i])
            break;
    }
    switch (i)
    {
    case 0:
        Harl.complain(levels[0]);
    case 1:
        Harl.complain(levels[1]);
    case 2:
        Harl.complain(levels[2]);
    case 3:
        Harl.complain(levels[3]);
        break;
    default:
        std::cout << DEFAULT_LV << '\n';
        break;
    }
}

int main(int arc, char **arv)
{
    if (arc != 2)
    {
        std::cout << "Usage: " << arv[0] << " <complainLevel>\n";
        std::cout << "<complainLevel> can be DEBUG, INFO, WARNING, ERROR\n";
        return 0;
    }
    harlFilter(arv[1]);
    return 0;
}