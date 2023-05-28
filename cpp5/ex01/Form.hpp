#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	 public:
		Form(std::string name, int sign, int exe);
		~Form();
		Form (const Form &copy);
		Form &operator=(const Form&);
		void beSigned(Bureaucrat &worker);
		std::string getName(void);
		bool getSigned(void);
		int getGradeSign(void);
		int getGradeExe(void);
		class GradeTooLowException : public std::exception {
				const char* what() const throw();
		};
		class GradeTooHighException : public std::exception {
				const char* what() const throw();
		};
		class AlreadySigned : public std::exception {
				const char* what() const throw();
		};
	 private:
		Form();
		const std::string _name;
		bool _signed;
		const int _grade_to_signed;
		const int _grade_to_exe;
};

std::ostream &operator<< (std::ostream &out, Form &form);
#endif
