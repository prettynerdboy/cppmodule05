#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include <fstream>
class ShrubberyCreationForm : public AForm
{
    private:
	    std::string _target;
    protected:
        virtual void executeAction() const;
    public:
	    ShrubberyCreationForm(std::string target = "Default");
	    ShrubberyCreationForm(const ShrubberyCreationForm &other);
	    ~ShrubberyCreationForm();
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
};

#endif