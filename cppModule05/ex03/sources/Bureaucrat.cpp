#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default name"), grade(1) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name(src.getName()), grade(src.getGrade()) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
    grade = src.getGrade();
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return RED "Bureaucrat grade is too high. Must be between 1 and 150." RESET;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return PURPLE "Bureaucrat grade is too low. Must be between 1 and 150." RESET;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

std::string Bureaucrat::getName() const
{
    return name;
}

void Bureaucrat::incrementGrade()
{
    grade--;
    if (grade < 1)
        throw GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
    grade++;
    if (grade > 150)
        throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &outputStream, Bureaucrat const &src)
{
    outputStream << src.getName() << ", bureaucrat grade " << src.getGrade() << ".\n";
    return outputStream;
}

void Bureaucrat::signForm(AForm &form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << GREEN << getName() << " signed " << form.getName() << '\n'
                  << RESET;
    }
    catch (const std::exception &e)
    {
        std::cout << RED << getName() << " couldn't sign " << form.getName()
                  << " because " << e.what() << '\n'
                  << RESET;
    }
}

void Bureaucrat::executeForm(const AForm &form) const
{
    try
    {
        form.execute(*this);
        std::cout << GREEN << getName() << " executed " << form.getName() << '\n'
                  << RESET;
    }
    catch (const std::exception &e)
    {
        std::cout << getName() << " couldn't execute " << form.getName()
                  << " because " << e.what() << '\n';
    }
}
