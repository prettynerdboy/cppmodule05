#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm("Robotomy Request", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
: AForm(other), _target(other._target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

// virtual
void RobotomyRequestForm::executeAction() const
{
	std::cout << "Drilling noises..." << std::endl;
	if (rand() % 2)
	{
		std::cout << _target << " successfully robotomized." << std::endl;
	}
	else
	{
		std::cout << _target << " failed to robotomize." << std::endl;
	}
};
