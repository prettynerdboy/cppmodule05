#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include <math.h>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
	    std::string _target;
    protected:
        virtual void executeAction() const;
    public:
	    RobotomyRequestForm(std::string target = "Default");
	    RobotomyRequestForm(RobotomyRequestForm const &other);
	    virtual ~RobotomyRequestForm();
        RobotomyRequestForm &operator=( RobotomyRequestForm const &other );
};

#endif 