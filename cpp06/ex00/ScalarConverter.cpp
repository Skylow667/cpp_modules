#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>
#include <limits.h>

void printFloat(float nb, int print, std::string str);
void printDouble(double nb, int print, std::string str);
void printChar(const char nb, int print, std::string str);
void printInt(int nb, int print, std::string str);

ScalarConverter::ScalarConverter(){
}

ScalarConverter::~ScalarConverter(){
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy){
	*this = copy;
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter &copy){
	if (&copy != this)
	{
		this->~ScalarConverter();
		new (this) ScalarConverter();
	}
	return (*this);
}

static bool isInt(std::string str) {
	int i = 0;

	if ((str[i] == '-' || str[i] == '+') && str.size() != 1)
		i++;
	while (str[i]) {
		if (!std::isdigit(str[i]))
			return false;
		i++;
	}
	return true;
}

static bool isFloat(std::string str) {
	int i = 0;
	int point = 0;

	if ((str[i] == '-' || str[i] == '+') && str.size() != 1)
		i++;
	while (str[i + 1]) {
		if (str[i] == '.') {
			point++;
			if (i == 0 || str[i + 1] == 'f')
				return false;
		}
		if ((!std::isdigit(str[i]) && str[i] != '.') || point > 1)
			return false;
		i++;
	}
	if (str[i] == 'f' && str.size() != 1)
		return true;
	return false;
}

static bool isDouble(std::string str) {
	int i = 0;
	bool point = false;

	if ((str[i] == '-' || str[i] == '+') && str.size() != 1)
		i++;
	while (str[i]) {
		if (str[i + 1] && str[i] == '.' && i != 0 && point == false)
			point = true;
		else if (str[i] == '.' && (point == true || i == 0 || str[i + 1] == 'f'))
			return false;
		else if (!std::isdigit(str[i]))
			return false;
		i++;
	}
	return true;
}

static bool isChar(std::string str) {
	if (str.size() == 1 && str[0] > 31 && str[0] < 127)
		return true;
	return false;
}

void printChar(const char nb, int print, std::string str) {
	if (std::isprint(nb) && print != 2)
		std::cout << "char: '" << nb << "'" << std::endl;
	if (print == 1) {
		printInt(static_cast<int>(nb), 0, str);
		printFloat(static_cast<float>(nb), 2, str);
		printDouble(static_cast<double>(nb), 2, str);
	}
	else if (str != "nan" && str != "nanf" && str != "-inff" && str != "-inf" && str != "+inff" && str != "+inf" && !std::isprint(nb))
		std::cout << "char: Non displayable" << std::endl;
	else if (!std::isprint(nb) || print == 2)
		std::cout << "char: Impossible" << std::endl;

}

void printInt(int nb, int print, std::string str) {
	if (print == 1) {
		if (nb < 0)
			printChar(static_cast<char>(nb), 2, str);
		else	
			printChar(static_cast<char>(nb), 0, str);
	}
	double double_nb = std::strtod(str.c_str(), NULL);
	if (str != "nan" && str != "nanf" && str != "-inff" && str != "-inf" && str != "+inff" && str != "+inf" && double_nb < INT_MAX && double_nb > INT_MIN)
		std::cout << "int: " << nb << std::endl;
	else
		std::cout << "int: Impossible" << std::endl;
	if (print == 1) {
		printFloat(static_cast<float>(double_nb), 2, str);
		printDouble(double_nb, 2, str);
	}
}

void printFloat(float nb, int print, std::string str) {
	if (print == 1) {
		if (nb < 0)
			printChar(static_cast<char>(nb), 2, str);
		else	
			printChar(static_cast<char>(nb), 0, str);
		printInt(static_cast<int>(nb), 0, str);
	}
	std::cout << "float: " << std::setprecision(2) << std::fixed << nb << "f" << std::endl;
	if (print == 1)
		printDouble(std::strtod(str.c_str(), NULL), 0, str);
}

void printDouble(double nb, int print, std::string str) {
	if (print == 1) {
		if (nb < 0)
			printChar(static_cast<char>(nb), 2, str);
		else	
			printChar(static_cast<char>(nb), 0, str);
		printInt(static_cast<int>(nb), 0, str);
		printFloat(static_cast<float>(nb), 0, str);
	}
	std::cout << "double: " << std::setprecision(2) << nb << std::endl;
}

void printError() {
	std::cout << "char: Impossible" << std::endl; 
	std::cout << "int: Impossible" << std::endl; 
	std::cout << "float: Impossible" << std::endl; 
	std::cout << "double: Impossible" << std::endl; 
}

void ScalarConverter::Convert(std::string str) {
	if (isInt(str))
		printInt(std::atoi(str.c_str()), 1, str);
	else if (isFloat(str) || str == "-inff" || str == "+inff" || str == "nanf")
		printFloat(std::atof(str.c_str()), 1, str);
	else if (isDouble(str) || str == "-inf" || str == "+inf" || str == "nan") {
		char *endPtr;
		printFloat(std::strtod(str.c_str(), &endPtr), 1, str);
	}
	else if (isChar(str))
		printChar(str[0], 1, str);
	else
		printError();
}
