#include "RPN.hpp"
#include <exception>
#include <iostream>
#include <sstream>
#include <string>

int	main(int ac, char **av)
{
	std::stack<float> stk;
	if (ac != 2) {
		std::cerr << "This program take only one argument!" << std::endl;
		return (1);
	}
	try {
		RPN::resolveRPN(av[1], stk);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
