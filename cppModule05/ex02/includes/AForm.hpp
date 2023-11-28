#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include <fstream>

#include "Bureaucrat.hpp"

#define RESET "\e[0m"
#define DRED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLUE "\e[34m"
#define PURPLE "\e[35m"
#define CYAN "\033[36m"
#define RED "\e[91m"

class Bureaucrat;

class AForm
{
public:
    AForm();
    AForm(const std::string &name, const int gradeToSign,
          const int gradeToExecute);
    AForm(const AForm &src);
    AForm &operator=(const AForm &src);
    ~AForm();

    // getters:
    std::string getName() const;
    bool getSignedStatus() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Member function to sign the AForm
    void beSigned(const Bureaucrat &bureaucrat);

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
    class UnsignedFormException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    // Pure virtual function to be overridden by concrete classes
    virtual void execute(const Bureaucrat &executor) const = 0;

private:
    const std::string name;
    bool signedStatus;
    const int gradeToSign;
    const int gradeToExecute;
};

std::ostream &operator<<(std::ostream &o, AForm const &src);

#endif