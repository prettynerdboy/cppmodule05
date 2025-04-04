#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Form;

class Bureaucrat
{
    private:
        const std::string _name;
        int               _grade;
    public:
        //constructor
        Bureaucrat(std::string name="dafault" ,int grade=1);
        // destructor
        ~Bureaucrat();
        //copy constructor
        Bureaucrat(Bureaucrat const &other);
        //copy assignment
        Bureaucrat &operator=(Bureaucrat const &other);
        //grade operator
        void incrementGrade();
        void decrementGrade();
        //accessor
        const std::string &getName() const;
        int               getGrade() const;
        // sign form
        void signForm(Form &form);
        //exception class
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Bureaucrat : Grade is too high!");
                }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Bureaucrat : Grade is too low!");
                }
        };
};

std::ostream &operator<<(std::ostream &os , Bureaucrat const &bureaucrat);

#endif
//constructorをプライベートメンバにすることで意図的に使わせない実装もできる。