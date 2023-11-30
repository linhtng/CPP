#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void testShrubberyCreationForm()
{
    try
    {
        Bureaucrat bureaucrat("John", 1);

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

void testShrubberyCreationFormException()
{
    try
    {
        Bureaucrat bureaucrat("John", 144);

        // Create forms
        // ShrubberyCreationForm shrubberyForm("home");
        ShrubberyCreationForm shrubberyForm;
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

        RobotomyRequestForm formR("8-Bit");
        std::cout << formR << '\n';

        bureaucrat.signForm(formR); // comment this to throw UnsignedFormException

        bureaucrat.executeForm(formR);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }
}

void testRobotomyRequestFormException()
{
    try
    {
        Bureaucrat bureaucrat("John", 65);
        std::cout << bureaucrat << '\n';

        RobotomyRequestForm formR("8-Bit");
        std::cout << formR << '\n';

        bureaucrat.signForm(formR); // comment this to throw UnsignedFormException

        bureaucrat.executeForm(formR);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }
}

void testPresidentialPardonForm()
{
    try
    {
        Bureaucrat bureaucrat("John", 5);
        std::cout << bureaucrat << '\n';

        PresidentialPardonForm formP("Nobody");
        std::cout << formP << '\n';

        bureaucrat.signForm(formP); // comment this to throw UnsignedFormException

        bureaucrat.executeForm(formP);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }
}

void testPresidentialPardonFormException()
{
    try
    {
        Bureaucrat bureaucrat("John", 15);
        std::cout << bureaucrat << '\n';

        PresidentialPardonForm formP("Nobody");
        std::cout << formP << '\n';

        bureaucrat.signForm(formP); // comment this to throw UnsignedFormException

        bureaucrat.executeForm(formP);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }
}

int main()
{
    testShrubberyCreationForm();
    testShrubberyCreationFormException();
    testRobotomyRequestForm();
    testRobotomyRequestFormException();
    testPresidentialPardonForm();
    testPresidentialPardonFormException();

    return 0;
}