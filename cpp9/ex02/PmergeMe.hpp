#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <cctype>
#include <iostream>
#include <iterator>
#include <vector>
#include <deque>
#include <limits.h>
#include <cstdlib>
#include <algorithm>

class PmergeMe {
	 private:
		PmergeMe(void);
		~PmergeMe();
		PmergeMe (const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe&);
	 public:
		static std::deque<int> mergeInsertSortDeque(std::deque<int> container);
		static std::vector<int> mergeInsertSortVector(std::vector<int> container);
		template<typename T>
		static void parsArg(char **av, T *container) {
			for (int i = 1; av[i]; i++) {
				for(int j = 0; av[i][j]; j++) {
					if (!std::isdigit(av[i][j]))
						throw (std::logic_error("The program take only positive and non null number!"));
				}
				long nb = std::atoll(av[i]);
				if (nb <= 0 || nb > INT_MAX)
					throw (std::logic_error("The program take only positive and non null number!"));
				container->push_back(nb);	
			}
		}


		template<typename T>
		static void insertSort(int end, T & container) {
			int    i = 1;
			while (i < end)
			{
				int    j = i;
				while (j > 0  && container[j - 1] > container[j])
				{
					std::swap(container[j], container[j - 1]);
					j--;
				}
				i++;
			}
		}
};

#endif
