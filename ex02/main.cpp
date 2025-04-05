#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat hira("Hira", 140);
        Bureaucrat taro("Taro", 50);
        Bureaucrat shinzo("Shinzo", 5);

        ShrubberyCreationForm shrubbery("Park");
        std::cout << shrubbery << std::endl;

        hira.signForm(shrubbery);
        std::cout << shrubbery << std::endl;

        hira.executeForm(shrubbery);

        taro.executeForm(shrubbery);
        std::cout << "ShrubberyCreationForm test completed.\n"
                  << std::endl;

        RobotomyRequestForm robotomy("robot");
        std::cout << robotomy << std::endl;

        taro.signForm(robotomy);
        std::cout << robotomy << std::endl;

        taro.executeForm(robotomy);

        shinzo.executeForm(robotomy);
        std::cout << "RobotomyRequestForm test completed.\n"
                  << std::endl;

        PresidentialPardonForm pardon("hira");
        std::cout << pardon << std::endl;

        shinzo.signForm(pardon);
        std::cout << pardon << std::endl;

        shinzo.executeForm(pardon);
        std::cout << "PresidentialPardonForm test completed.\n"
                  << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}