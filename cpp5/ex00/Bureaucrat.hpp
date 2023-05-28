#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <exception>
# include <string>
# include <iostream>

class Bureaucrat
{
	 public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat & copy);
		Bureaucrat &operator=(const Bureaucrat & copy);	
		~Bureaucrat();
		std::string getName(void) const;
		int getGrade(void) const;
		void upGrade(int up);
		void downGrade(int down);
		class GradeTooHighException : public std::exception {
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
				const char* what() const throw();
		};
	 private:
		Bureaucrat();
		const std::string _name;
		int _grade;
};

std::ostream &operator<< (std::ostream &out, Bureaucrat &worker);
#endif
