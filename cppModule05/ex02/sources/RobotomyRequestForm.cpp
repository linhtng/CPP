#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default Robotomy", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("Param Robotomy", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : target(src.getTarget()) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
    target = src.getTarget();
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

const char *RobotomyRequestForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high. Must be between 1 and 150.";
}

const char *RobotomyRequestForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low. Must be between 1 and 150.";
}

std::string RobotomyRequestForm::getTarget() const
{
    return target;
}

std::ostream &operator<<(std::ostream &outputStream, RobotomyRequestForm const &src)
{
    outputStream << CYAN "RobotomyRequestForm " << src.getName()
                 << (src.getSignedStatus() ? " is signed" : " is unsigned")
                 << ". Grade to sign: " << src.getGradeToSign()
                 << ". Grade to execute: " << src.getGradeToExecute() << "\n" RESET;
    return outputStream;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    AForm::execute(executor); // Check if the form is signed and grade is high enough
    std::srand(std::time(0)); // Seed for randomization

    if (std::rand() % 2 == 0)
    {
        std::cout << executor.getName() << " executed " << getName() << " for " << target << ": Robotomized successfully!" << std::endl;
    }
    else
    {
        std::cout << executor.getName() << " executed " << getName() << " for " << target << ": Robotomy failed." << std::endl;
    }
}