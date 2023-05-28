#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <exception>
#include <iostream>
#include <algorithm>
#include <vector>

template<typename T>
void easyfind(T first, int second) {
	typename T::iterator it;
	it = std::find(first.begin(), first.end(), second);
	if (it == first.end())
		std::cout << second << " is not find!" << std::endl;
	else
		std::cout << second << " is find!" << std::endl;
}

#endif
