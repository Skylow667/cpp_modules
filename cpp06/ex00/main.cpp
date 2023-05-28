#include <cstdlib>
#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << "The programme take only 1 argument!" << std::endl;
		return (1);
	}
	std::string str = av[1];
	ScalarConverter::Convert(str);
	return (0);
}
