#include "Bureaucrat.hpp"
#include <exception>

Bureaucrat::Bureaucrat() {}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
	return ("The grade is too low!");
}

const char * Bureaucrat::GradeTooHighException::what() const throw() {
	return ("The grade is too High!");
}

Bureaucrat::Bureaucrat(const std::string name, int grade):_name(name){
	_grade = grade;
	if (_grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else if (_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
}

Bureaucrat::Bureaucrat(const Bureaucrat & copy):_name(copy._name) {
	this->_grade = copy._grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat & copy) {
	if (this != &copy) {
		this->~Bureaucrat();
		new(this) Bureaucrat(copy._name, copy._grade);
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

std::ostream &operator<< (std::ostream &out, Bureaucrat &worker) {
	out << worker.getName() << ", bureaucrat grade " << worker.getGrade() << std::endl;
	return (out);
}
