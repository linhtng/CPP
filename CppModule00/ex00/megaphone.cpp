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
            std::string s(*argv);
            for ( std::string::iterator it=s.begin(); it!=s.end(); ++it)
                std::cout << (char) toupper(*it);
            argv++;
        }
    }
    std::cout << '\n';
    return 0;
}