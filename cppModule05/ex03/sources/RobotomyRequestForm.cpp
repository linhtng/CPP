#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : target(src.getTarget()) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
    target = src.getTarget();
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

std::string RobotomyRequestForm::getTarget() const
{
    return target;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    AForm::execute(executor);
    std::srand(std::time(0)); // Seed for randomization

    std::cout << "It's drillin' time!\n";

    if (std::rand() % 2 == 0)
        std::cout << target << ": Robotomized successfully!\n";
    else
        std::cout << target << ": Robotomy failed.\n";
}