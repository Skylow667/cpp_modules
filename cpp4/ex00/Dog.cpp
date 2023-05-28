#include "Dog.hpp"

Dog::Dog(void):Animal(){
	std::cout << "Dog constructor called!" << std::endl;
	this->type = "Dog";
}

Dog::~Dog(){
	std::cout << "Dog destructor called!" << std::endl;
}

Dog::Dog(const Dog &copy):Animal(copy){
}

Dog & Dog::operator=(const Dog &copy){
	this->type = copy.type;
	return (*this);
}

void Dog::makeSound(void) const {
	std::cout << "The dog barks!" << std::endl;
}
