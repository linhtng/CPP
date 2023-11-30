#ifndef Intern_HPP
#define Intern_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
public:
    Intern();
    Intern(const std::string &name, int grade);
    Intern(const Intern &src);
    Intern &operator=(const Intern &src);
    ~Intern();

    AForm *makeForm(const std::string &formName, const std::string &target) const;

private:
    typedef AForm *(Intern::*createFormFunction)(const std::string &) const;

    // Helper function to create a specific form based on the provided function pointer
    AForm *createForm(const std::string &target, createFormFunction createFunction) const;

    AForm *createShrubberyCreationForm(const std::string &target) const;
    AForm *createRobotomyRequestForm(const std::string &target) const;
    AForm *createPresidentialPardonForm(const std::string &target) const;
};

#endif