#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <list>
#include <vector>

class Span
{
	 public:
		 Span(unsigned int N);
		~Span();
		Span (const Span &copy);
		Span &operator=(const Span&);
		void addNumber(int nb);
		void addNumbers(std::vector<int>::iterator it, std::vector<int>::iterator ite);
		int shortestSpan(void);
		int longestSpan(void);
	 private:
		Span();
		std::vector<int> _lst;
		unsigned int _size;
		
};

#endif
