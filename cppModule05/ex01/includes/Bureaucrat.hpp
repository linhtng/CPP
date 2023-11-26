#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

#define RED "\e[91m"
#define PURPLE "\e[35m"
#define RESET "\e[0m"

class Bureaucrat
{
public:
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &src);
    Bureaucrat &operator=(const Bureaucrat &src);
    ~Bureaucrat();

    void makeSound() const;
    std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();

    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw();
    };

private:
    const std::string name;
    int grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &src);

#endif