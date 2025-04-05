#include "AForm.hpp"
#include "Bureaucrat.hpp"

//constructor
AForm::AForm(
	std::string name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
};

//desutructor
AForm::~AForm()
{
    std::cout << "AForm " << this->_name << " has been disposed." << std::endl;
}

// copy constructor
AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	this->operator=(other);
}

// copy assignment
AForm &AForm::operator=(AForm const &other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return *this;
}

//accesor
const std::string &AForm::getName() const
{
	return this->_name;
}

bool AForm::getIsSigned() const
{
	return this->_isSigned;
}

int AForm::getGradeToSign() const
{
	return this->_gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

// Aform action
void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (_gradeToSign < bureaucrat.getGrade())
		throw GradeTooLowException();
	_isSigned = true;
}
void AForm::execute(Bureaucrat const &executor) const
{
	if(!_isSigned)
		throw (FormNotSignedException());
	if(executor.getGrade() > _gradeToExecute)
		throw (GradeTooHighException());
	executeAction();
}

std::ostream &operator<<(std::ostream &os, AForm const &Aform)
{
	os << "AForm " << Aform.getName() << ", signed: " << Aform.getIsSigned() << ", grade to sign: " << Aform.getGradeToSign() << ", grade to execute: " << Aform.getGradeToExecute();
	return os;
}
