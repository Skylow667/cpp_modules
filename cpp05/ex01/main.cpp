#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	try  {
		Bureaucrat manager("Manager", 15);
		Form contract("Contract", 100, 50);

	std::cout << contract;
	std::cout << manager;
	manager.signForm(contract);
	manager.downGrade(90);
	std::cout << manager;
	manager.signForm(contract);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
