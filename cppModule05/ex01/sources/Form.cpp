#include "Form.hpp"

Form::Form() : name("Default name"), signedStatus(false),
               gradeToSign(150), gradeToExecute(150) {}

Form::Form(const std::string &name, const int gradeToSign, const int gradeToExecute)
    : name(name), signedStatus(false),
      gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &src) : name(src.getName()), signedStatus(src.getSignedStatus()),
                              gradeToSign(src.getGradeToSign()),
                              gradeToExecute(src.getGradeToExecute()) {}

Form &Form::operator=(const Form &src)
{
    signedStatus = src.getSignedStatus();
    return *this;
}

Form::~Form() {}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high. Must be between 1 and 150.";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "GradeTooLowException: Form grade is out of bounds [1-150] or bureaucrat's grade is not high enough.";
}

bool Form::getSignedStatus() const
{
    return signedStatus;
}

std::string Form::getName() const
{
    return name;
}

int Form::getGradeToSign() const
{
    return gradeToSign;
}

int Form::getGradeToExecute() const
{
    return gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= gradeToSign)
        signedStatus = true;
    else
        throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &outputStream, Form const &src)
{
    outputStream << CYAN "Form " << src.getName()
                 << (src.getSignedStatus() ? " is signed" : " is unsigned")
                 << ". Grade to sign: " << src.getGradeToSign()
                 << ". Grade to execute: " << src.getGradeToExecute() << "\n" RESET;
    return outputStream;
}