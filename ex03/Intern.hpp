#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    private:
        static const unsigned int _formListNum = 3;
        static const std::string _formList[_formListNum];

    public:
	Intern();
	Intern(Intern const &src);
	~Intern();
	Intern &operator=(Intern const &rhs);

	AForm *makeForm(std::string formName, std::string target);
};

#endif