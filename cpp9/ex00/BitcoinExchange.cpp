#include "BitcoinExchange.hpp"
#include <cctype>
#include <exception>
#include <fstream>
#include <ios>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <climits>

static bool parsDate(std::string date, std::string sep) {
	int day_per_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	char *pEnd = NULL;

	for (int i = 0; date[i]; i++) {
		if (!std::isdigit(date[i]) && date[i] != '-' && date[i] != '.'
			&& ((sep == "," && date[i] != ',')
			|| (sep == " | " && date[i] != ',' && date[i] != '|' && date[i] != ' ')))
			return false;
		if (date[i] == '.' && !std::isdigit(date[i + 1]))
			return false;
	}

	if (std::count(date.begin(), date.end(), '-') != 2
		|| std::count(date.begin(), date.end(), '.') > 1 
		|| (sep == "," && std::count(date.begin(), date.end(), ',') != 1)
		|| (sep == "," && std::count(date.begin(), date.end(), ' ') > 0)
		|| (sep == " | " && std::count(date.begin(), date.end(), ' ') > 2)
		|| (sep == " | " && std::count(date.begin(), date.end(), '|') != 1))
		return false;

	int year = std::strtod(date.substr(0, date.find('-')).c_str() ,&pEnd);
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		day_per_month[1]++;
	if (year > 2050 || year < 2009)
		return false;

	int month = std::strtod(date.substr(date.find('-') + 1, date.find('-', 1)).c_str(), &pEnd);
	int day = std::strtod(date.substr(date.find_last_of("-") + 1).c_str() , &pEnd);
	if (month < 1 || month > 12)
		return false;

	if (day > day_per_month[month - 1])
		return false;

	if (sep == "," && date[10] != ',')
		return false;

	if (sep == " | " && date.find(sep) == std::string::npos)
		return false;

	int rate = std::strtod(date.substr(date.find(sep) + sep.size(), date.size()).c_str(), &pEnd);
	if (rate < 0 || rate > INT_MAX)
		return false;

	if (pEnd && pEnd[0])
		return false;
	return true;
}

BitcoinExchange::BitcoinExchange(){
	std::ifstream data;
	std::string str;
	int	i = 0;

	data.open("data.csv");
	if (!data)
		throw (std::logic_error("data.csv cant be open!"));
	std::getline(data, str);
	if (str != "date,exchange_rate")
		throw (std::logic_error("data.csv first line is bad! (date,exchange_rate)"));
	while (std::getline(data, str)) {
		if (!parsDate(str, ",")) {
			std::cout << "Error: line " << i + 2 ;
			throw (std::logic_error(": the data file has bad entries!"));
		}
		int pos = str.find(',');
		_data.insert(std::pair<std::string, float>(str.substr(0, pos), std::atof(str.substr(pos + 1, str.size()).c_str())));
		i++;
	}
	data.close();
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy){
	*this = copy;
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &copy){
	if (&copy != this)
	{
		this->~BitcoinExchange();
		new (this)BitcoinExchange();
	}
	return (*this);
}

void	BitcoinExchange::doExchange(std::string file)
{
	std::string str;
	std::ifstream input;

	input.open(file.c_str());
	if (!input)
		throw (std::logic_error("input file cant be open!"));
	std::getline(input, str);
	if (str != "date | value")
		throw (std::logic_error("input file first line is bad! (date | value)"));
	while (std::getline(input, str)) {
		int pos = str.find('|');
		std::string date = str.substr(0, pos - 1);
		std::string nb = str.substr(pos + 2, str.size());
		if (std::strtod(nb.c_str(), NULL) < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else if (std::strtod(nb.c_str(), NULL) > 1000)
			std::cout << "Error: too large number." << std::endl;
		else if (str.find('|') == std::string::npos || parsDate(str, " | ") == false)
			std::cout << "Error: bad input => " << str << std::endl;
		else {
			std::map<std::string, float>::iterator it = _data.upper_bound(date);
			if (it == _data.begin() && _data.size() > 0)
				std::cout << "Error: no date below! => " << str <<std::endl;
			else if (it == _data.begin() && _data.size() == 0)
				throw (std::logic_error("Error: no mutch data in data.csv!"));
			else {
				it--;
				std::cout << date << " => " << nb;
				date = it->first;
				std::cout << " = " << _data[date] * std::atof(nb.c_str()) << std::endl; 
			}
		}
	}
	input.close();
}
