#include "Span.hpp"
#include <algorithm>
#include <exception>
#include <limits.h>

Span::Span(unsigned int N){
	_size = N;
}

Span::~Span(){
}

Span::Span(const Span &copy){
	*this = copy;
}

Span & Span::operator=(const Span &copy){
	if (&copy != this)
	{
		this->~Span();
		new(this) Span(copy._size);
	}
	return (*this);
}

void Span::addNumber(int nb) {
	if (_lst.size() >= _size)
		throw (std::logic_error("The vector is full!"));
	_lst.push_back(nb);
}

void Span::addNumbers(std::vector<int>::iterator it, std::vector<int>::iterator ite) {
	for ( ;it != ite; it++) {
		if (_lst.size() >= _size)
			throw (std::logic_error("The vector is full!"));
		_lst.push_back(*it);
	}
}

int	Span::longestSpan(void) {
	return (*std::max_element(_lst.begin(), _lst.end()) - *std::min_element(_lst.begin(), _lst.end()));
}

int Span::shortestSpan(void) {
	int min = INT_MAX;
	sort(_lst.begin(), _lst.end());
	for (std::vector<int>::iterator it = _lst.begin(); it != _lst.end() - 1; it++) {
		if (*(it + 1) - *it < min)
			min = *(it + 1) - *it;
	}
	return (min);
}
