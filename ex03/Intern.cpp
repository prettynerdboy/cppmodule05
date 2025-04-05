#include "Intern.hpp"

const std::string Intern::_formList[_formListNum] =
{
    "shrubbery creation",
    "robotomy request",
    "presidential pardon"
};

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
	(void)other;
}


Intern::~Intern()
{
}

Intern &Intern::operator=(Intern const &other)
{
	(void)other;
	return *this;
}

AForm *createShrubberyForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm *createRobotomyForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm *createPresidentialForm(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	AForm *(*formCreators[])(std::string) = {
		createShrubberyForm,
		createRobotomyForm,
		createPresidentialForm};
	for (size_t i = 0; i < _formListNum; ++i)
	{
		if (formName == _formList[i])
		{
			std::cout << "Intern creates " << _formList[i] << " form." << std::endl;
			return formCreators[i](target);
		}
	}
	std::cerr << "Error: Form name \"" << formName << "\" is invalid." << std::endl;
	return NULL;
}