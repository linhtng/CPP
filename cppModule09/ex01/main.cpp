#include "RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: RPN <inverted Polish mathematical expression>\n";
        return 1;
    }

    try
    {
        RPN rpn;
        int result = rpn.evaluate(argv[1]);
        std::cout << CYAN "Result: " << result << RESET << "\n";
    }
    catch (const std::runtime_error &e)
    {
        std::cout << RED << e.what() << RESET "\n";
        return 1;
    }

    return 0;
}