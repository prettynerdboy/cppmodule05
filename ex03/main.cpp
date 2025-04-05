#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern intern;

    AForm *formlist[]=
    {
        intern.makeForm("shrubbery creation", "home"),
        intern.makeForm("robotomy request", "Bender"),
        intern.makeForm("presidential pardon", "Ford"),
    };
    AForm *invalidForm = intern.makeForm("invalid form", "target");

    try
    {
        Bureaucrat erai("erai",1);
        for(size_t i=0; i<3 ;++i)
        {
            erai.signForm(*formlist[i]);
            erai.executeForm(*formlist[i]);
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    for (size_t i = 0; i < 3; ++i)
    {
        delete formlist[i];
    }
    delete invalidForm;

    return 0;
}

//ポインタを返す関数なので責任はmain