#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &src)
{
    (void)src;
}

Intern &Intern::operator=(const Intern &src)
{
    (void)src;
    return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
    createFormFunction formFunctions[3] = {&Intern::createShrubberyCreationForm,
                                           &Intern::createRobotomyRequestForm,
                                           &Intern::createPresidentialPardonForm};

    const std::string nameList[3] = {"shrubbery creation",
                                     "robotomy request",
                                     "presidential pardon"};

    for (int i = 0; i < 3; ++i)
    {
        if (nameList[i] == formName)
            return createForm(target, formFunctions[i]);
    }
    std::cout << RED "Error: Unknown form name '" << formName << "'" RESET << std::endl;
    return NULL;
}

AForm *Intern::createForm(const std::string &target, createFormFunction createFunction) const
{
    return (this->*createFunction)(target);
}

AForm *Intern::createShrubberyCreationForm(const std::string &target) const
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequestForm(const std::string &target) const
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(const std::string &target) const
{
    return new PresidentialPardonForm(target);
}
