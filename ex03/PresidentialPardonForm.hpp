#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string         _target;
    protected:
        virtual void        executeAction() const ;
    public:
                            PresidentialPardonForm(std::string target = "Default");
	                        PresidentialPardonForm(const PresidentialPardonForm &src);
	                        ~PresidentialPardonForm();

	PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

};
#endif