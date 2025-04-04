#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat asou("Asou", 50);
        Form taxForm("Tax Form", 45, 30);
        std::cout << taxForm << std::endl;
        asou.signForm(taxForm);
        std::cout << taxForm << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat yonezawa("Yonezawa", 40);
        Form contract("Contract Form", 50, 20);
        std::cout << contract << std::endl;
        yonezawa.signForm(contract);
        std::cout << contract << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Form invalidForm("Invalid Form high", 0, 150);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Form invalidForm("Invalid Form low", 151, 150);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}