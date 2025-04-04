#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeToSign;
        const int           _gradeToExecute;
    public:
        //default constructor
        Form(std::string name = "default", int gradeToSign = 1, int gradeToExecute = 1);
        //desutructor
        ~Form();
        // copy constructor
        Form(const Form &other);
        // copy assignment
        Form &operator=(const Form &other);
        // accessor
        const std::string &getName() const;
        bool               getIsSigned() const;
        int                getGradeToSign() const;
        int                getGradeToExecute() const;
        //besigned
        void               beSigned(Bureaucrat &bureaucrat);
        // exception class
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Form : Grade is too low!");
                }
        };
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Form : Grade is too high!");
                }
        };
};

std::ostream &operator<<(std::ostream &os, Form const &form);