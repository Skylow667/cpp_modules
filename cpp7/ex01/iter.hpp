#ifndef ITER_HPP
#define ITER_HPP
#include <stdexcept>
#include <iostream>

template<typename I, typename F>
void iter(I tab, int size, F ft) {
	if (size > static_cast<int>(sizeof(I)))
		throw (std::logic_error("The size send is too high!"));
	for (int i = 0; i < size; i++)
		ft(tab[i]);
}

#endif
