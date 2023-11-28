#include "Bureaucrat.hpp"
#include "Form.hpp"

void testForm()
{
    try
    {
        Form validForm("Valid", 1, 150);
        // Form invalidForm("Invalid", 0, 1);
        //  Form invalidForm2("Invalid", 1, 151);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }
}

void testSignForm()
{
    try
    {
        Bureaucrat bureaucrat("John", 5);
        std::cout << bureaucrat << '\n';

        Form formA("Test", 42, 242);
        std::cout << formA << '\n';

        bureaucrat.signForm(formA);
        std::cout << formA << '\n';
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }
}

void testSignFormException()
{
    try
    {
        Bureaucrat bureaucrat("John", 5);
        std::cout << bureaucrat << '\n';

        Form formA("Test", 1, 42);
        std::cout << formA << '\n';

        bureaucrat.signForm(formA);
        std::cout << formA << '\n';
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }
}

int main()
{
    // testForm();
    testSignForm();
    testSignFormException();

    return 0;
}