#include "Form.hpp"
#include "Bureaucrat.hpp"

//constructor
Form::Form(
	std::string name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
};

//desutructor
Form::~Form()
{
    std::cout << "Form " << this->_name << " has been disposed." << std::endl;
}

// copy constructor
Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	this->operator=(other);
}

// copy assignment
Form &Form::operator=(Form const &other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return *this;
}

//accesor
const std::string &Form::getName() const
{
	return this->_name;
}

bool Form::getIsSigned() const
{
	return this->_isSigned;
}

int Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

int Form::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

// besigned
void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (_gradeToSign < bureaucrat.getGrade())
		throw GradeTooLowException();
	_isSigned = true;
}

std::ostream &operator<<(std::ostream &os, Form const &form)
{
	os << "Form " << form.getName() << ", signed: " << form.getIsSigned() << ", grade to sign: " << form.getGradeToSign() << ", grade to execute: " << form.getGradeToExecute();
	return os;
}
