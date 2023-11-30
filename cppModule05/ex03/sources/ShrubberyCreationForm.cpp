#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : target(src.getTarget()) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
    target = src.getTarget();
    return *this;
}

std::string ShrubberyCreationForm::getTarget() const
{
    return target;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    AForm::execute(executor);
    std::ofstream outFile(target + "_shrubbery");
    if (outFile.is_open())
    {
        // ASCII art for a tree
        outFile << "  *  \n *** \n*****\n  |  \n";
        std::cout << executor.getName() << " executed ShrubberyCreationForm"
                  << " on target " << CYAN << target << '\n'
                  << RESET;
    }
    else
        throw std::runtime_error(RED "Failed to create file for shrubbery creation" RESET);
}