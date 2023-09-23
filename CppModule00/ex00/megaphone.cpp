#include <iostream>
#include <ctype.h>

#define NOISE "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << NOISE;
    else {
        argv++;
        while (*argv)
        {
            int index = 0;
            std::string s(*argv);
            while (s[index])
            {
                std::cout << (char) toupper(s[index]);
                index++;
            }
            argv++;
        }
    }
    std::cout << std::endl;
    return 0;
}