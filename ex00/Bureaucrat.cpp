#include "Bureaucrat.hpp"

//constructor
Bureaucrat::Bureaucrat(std::string name, int grade):_name(name)
{
    if(grade > 150)
        throw (GradeTooLowException());
    if(grade < 1)
        throw  (GradeTooHighException());
    _grade = grade;
}
//destructor
Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat " << this->_name << " fall down" << std::endl;
}

//copy constructor
Bureaucrat::Bureaucrat(Bureaucrat const &other)
{
    this->_grade=other.getGrade();
}

//copy assignment
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
    if(this != &other)
    {
        this->_grade=other.getGrade();
    }
    return (*this);
}

// grade operator
void Bureaucrat::incrementGrade()
{
    if(this->_grade + 1 > 150)
        throw (GradeTooLowException());
    this->_grade++;
}

void Bureaucrat::decrementGrade()
{
    if(this->_grade - 1 < 1)
        throw (GradeTooHighException());
    this->_grade--;
}

//accessor
const std::string &Bureaucrat::getName() const
{
    return (this->_name);
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}


std::ostream &operator<<(std::ostream &o, Bureaucrat const &bureaucrat)
{

	o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return o;
}