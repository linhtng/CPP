#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void testShrubberyCreationForm()
{
    try
    {
        Bureaucrat bureaucrat("John", 150);

        // Create forms
        ShrubberyCreationForm shrubberyForm("home");
        std::cout << shrubberyForm << '\n';

        bureaucrat.signForm(shrubberyForm); // comment this to throw UnsignedFormException

        bureaucrat.executeForm(shrubberyForm);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }
}

void testRobotomyRequestForm()
{
    try
    {
        Bureaucrat bureaucrat("John", 5);
        std::cout << bureaucrat << '\n';

        RobotomyRequestForm formR("Robot power");
        // std::cout << formR << '\n';

        formR.execute(bureaucrat);
        std::cout << formR << '\n';
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

        PresidentialPardonForm formP("Test");
        // std::cout << formP << '\n';

        formP.execute(bureaucrat);
        std::cout << formP << '\n';
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }
}

int main()
{
    testShrubberyCreationForm();
    // testSignForm();
    // testSignFormException();

    return 0;
}