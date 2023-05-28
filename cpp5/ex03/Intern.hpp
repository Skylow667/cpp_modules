#ifndef INTERN_HPP
#define INTERN_HPP
# include "Form.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"

class Bureaucrat;

class Intern
{
	 public:
		Intern();
		~Intern();
		Intern (const Intern &copy);
		Intern &operator=(const Intern&);
		Form *makeForm(std::string form_name, std::string target);
		class FormError : public std::exception {
				const char* what() const throw();
		};
};

#endif
