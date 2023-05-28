#include "Bureaucrat.hpp"
#include <exception>

const char * Bureaucrat::GradeTooLowException::what() const throw() {
	return ("The Bureaucrat grade is too low!");
}

const char * Bureaucrat::GradeTooHighException::what() const throw() {
	return ("The Bureaucrat grade is too High!");
}

Bureaucrat::Bureaucrat(const std::string name, int grade):_name(name){
	_grade = grade;
	if (_grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else if (_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy):_name(copy._name) {
	*this = copy;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &copy){
	if (&copy != this)
	{
		this->~Bureaucrat();
		new(this) Bureaucrat(copy.getName(), copy.getGrade());
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {
}

std::string Bureaucrat::getName(void) const {
	return (_name);
} 

int Bureaucrat::getGrade(void) const {
	return (_grade);
} 

void Bureaucrat::upGrade(int up) {
	if (_grade - up < 1)
		throw (Bureaucrat::GradeTooHighException());
	_grade -= up;
}

void Bureaucrat::downGrade(int down) {
	if (_grade + down > 150)
		throw (Bureaucrat::GradeTooLowException());
	_grade += down;
}

void Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e) {
		if (form.getSigned() == false)
			std::cout << _name << " couldn't signed " << form.getName() << " because his grade is too low" << std::endl;
		else
			throw (Form::AlreadySigned());
	}
}

std::ostream &operator<< (std::ostream &out, Bureaucrat &worker) {
	out << worker.getName() << ", bureaucrat grade " << worker.getGrade() << std::endl;
	return (out);
}

void Bureaucrat::executeForm(Form const & form) {
	if (this->getGrade() <= form.getGradeExe())
		std::cout << this->getName() << "  executed " << form.getName() << std::endl;
	else
		std::cout << this->getName() << "  can't executed " << form.getName() << " because his execution grade is too low!" << std::endl;
}
