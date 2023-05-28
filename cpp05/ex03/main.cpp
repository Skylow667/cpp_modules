#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void) {
	Intern someRandomIntern;
	Bureaucrat boss("boss", 1);
	Bureaucrat manager("Manager", 30);
	Bureaucrat employee("employee", 125);
	Bureaucrat worker("worker", 150);
	Form* rrf;

	std::cout << "Robotomy Form Test:" << std::endl;
	try  {
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		manager.signForm(*rrf);
		boss.signForm(*rrf);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	delete rrf;
	std::cout << "\nShrubbery Form Test:" << std::endl;
	try  {
		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		worker.signForm(*rrf);
		delete rrf;
		rrf = someRandomIntern.makeForm("shrubbery creation", "Sardo");
		manager.signForm(*rrf);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	delete rrf;
	std::cout << "\nPresidential Form Test:" << std::endl;
	try  {
		rrf = someRandomIntern.makeForm("presidential pardon", "Unknown");
		boss.signForm(*rrf);
		delete rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "Unknown.v2");
		manager.signForm(*rrf);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	delete rrf;
	std::cout << "\nUnknown Form Test:" << std::endl;
	try  {
		rrf = someRandomIntern.makeForm("Unknown form", "Someone");
		manager.signForm(*rrf);
		boss.signForm(*rrf);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
