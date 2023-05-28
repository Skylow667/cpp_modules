#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	 public:
		Form();
		Form(std::string name, int sign, int exe);
		virtual ~Form();
		Form (const Form &copy);
		Form &operator=(const Form&);
		virtual void beSigned(Bureaucrat &worker);
		std::string getName(void) const;
		bool getSigned(void) const ;
		int getGradeSign(void) const ;
		int getGradeExe(void) const;
		virtual void execute(Bureaucrat const & executor) const = 0;
		class GradeTooLowException : public std::exception {
				const char* what() const throw();
		};
		class GradeTooHighException : public std::exception {
				const char* what() const throw();
		};
		class ExecutionException : public std::exception {
				const char* what() const throw();
		};
		class AlreadySigned : public std::exception {
				const char* what() const throw();
		};
	 private:
		const std::string _name;
		bool _signed;
		const int _grade_to_signed;
		const int _grade_to_exe;
};

std::ostream &operator<< (std::ostream &out, Form &form);
#endif
