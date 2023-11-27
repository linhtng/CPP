#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default Shrubbery", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("Param Shrubbery", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : target(src.getTarget()) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
    target = src.getTarget();
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const char *ShrubberyCreationForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high. Must be between 1 and 150.";
}

const char *ShrubberyCreationForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low. Must be between 1 and 150.";
}

std::string ShrubberyCreationForm::getTarget() const
{
    return target;
}

std::ostream &operator<<(std::ostream &outputStream, ShrubberyCreationForm const &src)
{
    outputStream << CYAN "ShrubberyCreationForm " << src.getName()
                 << (src.getSignedStatus() ? " is signed" : " is unsigned")
                 << ". Grade to sign: " << src.getGradeToSign()
                 << ". Grade to execute: " << src.getGradeToExecute() << "\n" RESET;
    return outputStream;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    AForm::execute(executor); // Check if the form is signed and grade is high enough
    std::ofstream outFile(target + "_shrubbery");
    if (outFile.is_open())
    {
        // ASCII art for a tree
        outFile << "  *  \n *** \n*****\n  |  \n";
        std::cout << executor.getName() << " executed " << getName() << " for " << target << '\n';
    }
    else
        throw std::runtime_error("Failed to create file for shrubbery creation");
}