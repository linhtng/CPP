#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void testShrubberyCreationForm()
{
    Intern intern;

    AForm *shrubberyForm = intern.makeForm("shrubbery creation", "home");
    std::cout << *shrubberyForm;
    Bureaucrat bureaucrat("John", 50);

    try
    {
        bureaucrat.signForm(*shrubberyForm);
        bureaucrat.executeForm(*shrubberyForm);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    delete shrubberyForm;
}

void testRobotomyRequestForm()
{
    Intern intern;

    AForm *robotomyForm = intern.makeForm("robotomy request", "Bender");
    std::cout << *robotomyForm;
    Bureaucrat bureaucrat("John", 40);

    try
    {
        bureaucrat.signForm(*robotomyForm);
        bureaucrat.executeForm(*robotomyForm);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    delete robotomyForm;
}

void testPresidentialPardonForm()
{
    Intern intern;

    AForm *pardonForm = intern.makeForm("presidential pardo", "Nobody");
    std::cout << *pardonForm;
    Bureaucrat bureaucrat("John", 145);

    try
    {
        bureaucrat.signForm(*pardonForm);
        bureaucrat.executeForm(*pardonForm);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    delete pardonForm;
}

int main()
{
    testShrubberyCreationForm();
    std::cout << std::endl;
    testRobotomyRequestForm();
    std::cout << std::endl;
    testPresidentialPardonForm();

    return 0;
}