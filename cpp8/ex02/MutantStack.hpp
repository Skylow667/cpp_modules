#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <iostream>
#include <iterator>
#include <stack>
#include <vector>

template<typename T, typename Container=std::deque<T> >
class MutantStack : public std::stack<T, Container> {
	protected:
		using std::stack<T, Container>::c;
	 public:
		MutantStack() {}
		~MutantStack() {}
		MutantStack(const MutantStack &copy){
			*this = copy;
		}
		MutantStack & operator=(const MutantStack &copy){
			if (&copy != this)
			{
				this->~MutantStack();
				new (this) MutantStack();
			}
			return (*this);
		}
		typedef typename Container::iterator iterator;
		iterator begin() { 
			return (c.begin()); 
		}
		iterator end() { 
			return (c.end()); 
		}
};

#endif
