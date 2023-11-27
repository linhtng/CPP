#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

#define RED "\e[91m"
#define PURPLE "\e[35m"
#define CYAN "\033[36m"
#define RESET "\e[0m"

class Bureaucrat;

class Form
{
public:
    Form();
    Form(const std::string &name, const int gradeToSign,
         const int gradeToExecute);
    Form(const Form &src);
    Form &operator=(const Form &src);
    ~Form();

    // getters:
    std::string getName() const;
    bool getSignedStatus() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Member function to sign the form
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

private:
    const std::string name;
    bool signedStatus;
    const int gradeToSign;
    const int gradeToExecute;
};

std::ostream &operator<<(std::ostream &o, Form const &src);

#endif