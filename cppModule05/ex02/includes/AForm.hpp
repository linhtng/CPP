#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include <fstream>
#include "Bureaucrat.hpp"

#define RED "\e[91m"
#define PURPLE "\e[35m"
#define CYAN "\033[36m"
#define RESET "\e[0m"

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

    // pure virtual function:
    virtual void execute(const Bureaucrat &executor) const = 0;

private:
    const std::string name;
    bool signedStatus;
    const int gradeToSign;
    const int gradeToExecute;
};

std::ostream &operator<<(std::ostream &o, AForm const &src);

#endif