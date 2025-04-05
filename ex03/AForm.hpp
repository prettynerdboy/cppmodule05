#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeToSign;
        const int           _gradeToExecute;

    protected:
        virtual void       executeAction() const = 0;

    public:
        //default constructor
        AForm(std::string name = "default", int gradeToSign = 1, int gradeToExecute = 1);
        //desutructor
        virtual ~AForm();
        // copy constructor
        AForm(const AForm &other);
        // copy assignment
        AForm &operator=(const AForm &other);
        // accessor
        const std::string &getName() const;
        bool               getIsSigned() const;
        int                getGradeToSign() const;
        int                getGradeToExecute() const;
        //form action
        void               beSigned(Bureaucrat const &bureaucrat);
        void               execute(Bureaucrat const &executor) const;
        // exception class
        class GradeTooLowException : public std::exception
        {
            virtual const char *what() const throw()
            {
                return ("AForm : Grade is too low!");
            }
        };
        class GradeTooHighException : public std::exception
        {
            virtual const char *what() const throw()
            {
                return ("AForm : Grade is too high!");
            }
        };
        class FormNotSignedException : public std::exception
        {
            virtual const char *what() const throw()
            { 
                return ("Form is not signed!"); 
            }
        };
};

std::ostream &operator<<(std::ostream &os, AForm const &Aform);

#endif