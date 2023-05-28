#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2){
		std::cout << "the programe take only 1 argument!" << std::endl;
		return (1);
	}
	try {
		BitcoinExchange bitcoin = BitcoinExchange();
		bitcoin.doExchange(av[1]);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
