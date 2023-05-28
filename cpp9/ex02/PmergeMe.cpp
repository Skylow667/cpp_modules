#include "PmergeMe.hpp"
#include <stdexcept>

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &copy){
	*this = copy;
}

PmergeMe & PmergeMe::operator=(const PmergeMe &copy){
	if (&copy != this)
	{
		this->~PmergeMe();
		new (this) PmergeMe(copy);
	}
	return (*this);
}

std::vector<int> PmergeMe::mergeInsertSortVector(std::vector<int> container) {
	int mid = container.size() / 2;
	if (mid <= 1) {
		insertSort(container.size(), container);
		return (container);
	}
	std::vector<int> result, L, R;
	L = mergeInsertSortVector(std::vector<int>(container.begin(), container.begin() + mid));
	R = mergeInsertSortVector(std::vector<int>(container.begin() + mid, container.end()));
	insertSort(L.size(), L);
	insertSort(R.size(), R);
	std::merge(L.begin(), L.end(), R.begin(), R.end(), std::back_inserter(result));
	return result;
}

std::deque<int> PmergeMe::mergeInsertSortDeque(std::deque<int> container) {
	int mid = container.size() / 2;
	if (mid <= 1) {
		std::sort(container.begin(), container.end());
		return (container);
	}
	std::deque<int> result, L, R;
	L = mergeInsertSortDeque(std::deque<int>(container.begin(), container.begin() + mid));
	R = mergeInsertSortDeque(std::deque<int>(container.begin() + mid, container.end()));
	insertSort(L.size(), L);
	insertSort(R.size(), R);
	std::merge(L.begin(), L.end(), R.begin(), R.end(), std::back_inserter(result));
	return result;
}
