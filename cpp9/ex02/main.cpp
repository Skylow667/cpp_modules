#include "PmergeMe.hpp"
#include <ctime>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include <ctime>

int	main(int ac, char **av)
{
	if (ac == 1) {
		std::cout << "The program take 1 argument or more!" << std::endl;
		return (1);
	}
	std::deque<int> deque;
	std::vector<int> vector;
	double time_deque;
	double time_vector;
	try {
		clock_t t = clock();
		PmergeMe::parsArg(av, &deque);
		deque = PmergeMe::mergeInsertSortDeque(deque);
		t = clock() - t;
		time_deque = static_cast<double>(t) / CLOCKS_PER_SEC * 1000;
		t = clock();
		PmergeMe::parsArg(av, &vector);
		vector = PmergeMe::mergeInsertSortVector(vector);	
		t = clock() - t;
		time_vector = static_cast<double>(t) / CLOCKS_PER_SEC * 1000;
		std::cout << "Before:  ";
		for (int i = 1; i != ac; i++)
			std::cout << av[i] << " ";
		std::cout << std::endl << "After:   ";
		for (int i = 0; i != ac - 1; i++) {
			if (i != 0 && deque[i] < deque[i - 1]) {
				std::cout << std::endl;
				throw (std::logic_error("List unsorted!"));
			}
			std::cout << deque[i] << " ";
		}
		std::cout << std::endl << "Time to process a range of " << ac - 1;
		std::cout << " elements with std::deque " << time_deque << " us";
		std::cout << std::endl << "Time to process a range of " << ac - 1;
		std::cout << " elements with std::vector " << time_vector << " us" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	return (0);
}
