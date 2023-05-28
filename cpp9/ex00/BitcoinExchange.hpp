#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <map>

class BitcoinExchange
{
	 public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange (const BitcoinExchange &copy);
		BitcoinExchange &operator=(const BitcoinExchange&);
		void doExchange(std::string file);
	 private:
		std::map<std::string, float> _data;
};

#endif
