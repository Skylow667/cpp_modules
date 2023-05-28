#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

const char *Intern::FormError::what() const throw() {
	return ("This form does not exist!");
}

Intern::Intern(){
}

Intern::~Intern(){
}

Intern::Intern(const Intern &copy){
	*this = copy;
}

Intern & Intern::operator=(const Intern &copy){
	if (&copy != this)
	{
		this->~Intern();
		new(this) Intern();
	}
	return (*this);
}

Form *Intern::makeForm(std::string form_name, std::string target) {
	std::string form_tab[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	Form *tab_ft[3] = {new RobotomyRequestForm(target), new ShrubberyCreationForm(target), new PresidentialPardonForm(target)}; 

	for (int i = 0; i != 3; i++) {
		if (form_name == form_tab[i]) {
			for (int j = i + 1 ;j != 3; j++)
				delete tab_ft[j];
			return (tab_ft[i]);
		}
		delete tab_ft[i];
	}
	throw (Intern::FormError());
	return (NULL);
}
