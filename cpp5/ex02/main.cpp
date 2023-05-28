#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) {
	Bureaucrat boss("boss", 1);
	Bureaucrat manager("Manager", 30);
	Bureaucrat employee("employee", 125);
	Bureaucrat worker("worker", 150);

	try  {
		std::cout << "Shrubbery test:" << std::endl;
		ShrubberyCreationForm contract1("Contract1");
		worker.signForm(contract1);
		employee.signForm(contract1);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try  {
		std::cout << "\nRobotomy test:" << std::endl;
		RobotomyRequestForm contract2("Contract2");
		manager.signForm(contract2);
		RobotomyRequestForm robotest("robotest");
		worker.signForm(robotest);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try  {
		std::cout << "\nPresidential test:" << std::endl;
		PresidentialPardonForm contract3("Contract3");
		boss.signForm(contract3);
		PresidentialPardonForm test("Some test form");
		manager.signForm(test);
		worker.signForm(test);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
