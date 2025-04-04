#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
    std::cout <<"constructor test" <<std::endl;
    Bureaucrat test;
    std::cout << test <<std::endl;
    try
    {
        Bureaucrat koizumi("Koizumi", 100);
        std::cout << koizumi << std::endl;
        koizumi.incrementGrade();
        std::cout << "After increment: " << koizumi << std::endl;
        koizumi.decrementGrade();
        std::cout << "After decrement: " << koizumi << std::endl;
        Bureaucrat high("High", 0);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        std::cout <<"invalide grade" <<std::endl;
        Bureaucrat low("Low", 151); // 例外発生
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    try
    {
        std::cout <<"grade too low test" <<std::endl;
        Bureaucrat abe("Abe", 150);
        std::cout << abe << std::endl;
        abe.decrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        std::cout <<"grade too high test" <<std::endl;
        Bureaucrat sakamoto("Sakamoto", 1);
        std::cout << sakamoto << std::endl;
        sakamoto.incrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        std::cout <<"copy assignment test" <<std::endl;
        Bureaucrat yamada("Yamada", 50);
        Bureaucrat suzuki("Suzuki", 75);
        std::cout << "Before assignment: " << suzuki << std::endl;
        suzuki = yamada;
        std::cout << "After assignment: " << suzuki << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}