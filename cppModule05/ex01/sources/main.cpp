#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat bureaucrat("John", 5);
        std::cout << bureaucrat << std::endl;

        bureaucrat.incrementGrade();
        std::cout << bureaucrat << std::endl;

        bureaucrat.decrementGrade();
        std::cout << bureaucrat << std::endl;

        // Uncomment the line below to test exception handling
        // Bureaucrat invalidBureaucrat("Invalid", 0);
        // Bureaucrat invalidBureaucrat2("Invalid", 151);

        Bureaucrat bureaucratA;
        std::cout << bureaucratA << std::endl;

        bureaucratA.incrementGrade();
        std::cout << bureaucratA << std::endl;

        /* Bureaucrat bureaucratB("B", 150);
        std::cout << bureaucratB << std::endl;

        bureaucratB.decrementGrade();
        std::cout << bureaucratB << std::endl; */
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}