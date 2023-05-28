#include "Bureaucrat.hpp"
#include <exception>
#include <functional>

int main(void) {
	try  {
		Bureaucrat manager("Manager", 15);

		std::cout << manager;
		manager.upGrade(10);
		std::cout << manager;
		manager.downGrade(25);
		std::cout << manager;
		manager.upGrade(130);
		std::cout << manager;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
