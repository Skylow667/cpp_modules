#include "Brain.hpp"
#include <iostream>

Brain::Brain(){
	std::cout << "Brain constructor called!" << std::endl;
}

Brain::~Brain(){
	std::cout << "Brain destructor called!" << std::endl;
}

Brain::Brain(const Brain &copy){
	*this = copy;
}

Brain & Brain::operator=(const Brain &copy){
	for (int i = 0; i != 100; i++) {
		this->_ideas[i] = copy._ideas[i];
	}
	return (*this);
}

void Brain::setIdeas(std::string ideas) {
	int i;

	for (i = 0; !_ideas[i].empty(); i++) {
		if (i >= 100)
			std::cout << "Too much ideas!" << std::endl;
	}
	if (i >= 100)
		std::cout << "Too much ideas!" << std::endl;
	_ideas[i] = ideas;
}

void Brain::printIdeas() {
	for (int i = 0; !_ideas[i].empty(); i++) {
		std::cout << _ideas[i] << std::endl;
	}
}
