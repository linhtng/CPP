#include "AForm.hpp"

AForm::AForm() : name("Default name"), signedStatus(false),
                 gradeToSign(150), gradeToExecute(150) {}

AForm::AForm(const std::string &name, const int gradeToSign, const int gradeToExecute)
    : name(name), signedStatus(false),
      gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &src) : name(src.getName()), signedStatus(src.getSignedStatus()),
                                 gradeToSign(src.getGradeToSign()),
                                 gradeToExecute(src.getGradeToExecute()) {}

AForm &AForm::operator=(const AForm &src)
{
    signedStatus = src.getSignedStatus();
    return *this;
}

AForm::~AForm() {}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high. Must be between 1 and 150.";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low. Must be between 1 and 150.";
}

bool AForm::getSignedStatus() const
{
    return signedStatus;
}

std::string AForm::getName() const
{
    return name;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= gradeToSign)
        signedStatus = true;
    else
        throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &outputStream, AForm const &src)
{
    outputStream << CYAN "AForm " << src.getName()
                 << (src.getSignedStatus() ? " is signed" : " is unsigned")
                 << ". Grade to sign: " << src.getGradeToSign()
                 << ". Grade to execute: " << src.getGradeToExecute() << "\n" RESET;
    return outputStream;
}