#include "Harl.hpp"

// int main()
// {
//     Harl Harl;
//     Harl.complain("DEBUG");
//     Harl.complain("INFO");
//     Harl.complain("WARNING");
//     Harl.complain("ERROR");

//     return 0;
// }

int main(int arc, char **arv)
{
    if (arc < 2)
    {
        std::cout << "Usage: " << arv[0] << " <complainLevel>\n";
        std::cout << "<complainLevel> can be DEBUG, INFO, WARNING, ERROR\n";
        return 0;
    }
    Harl Harl;
    for (int i = 1; i < arc; ++i)
        Harl.complain(arv[i]);
    return 0;
}