#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <exception>
#include <string>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	 public:
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat & operator=(const Bureaucrat &copy);
		std::string getName(void) const;
		int getGrade(void) const;
		void upGrade(int up);
		void downGrade(int down);
		void signForm(Form &form);
		void executeForm(Form const & form);
		class GradeTooLowException : public std::exception {
				const char* what() const throw();
		};
		class GradeTooHighException : public std::exception {
				const char* what() const throw();
		};
	 private:
		const std::string _name;
		int _grade;
};

std::ostream &operator<< (std::ostream &out, Bureaucrat &worker);
#endif
