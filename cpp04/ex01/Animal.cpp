#include "Animal.hpp"

Animal::Animal(void){
	std::cout << "Animal constructor called!" << std::endl;
	this->type = "Animal";
}

Animal::~Animal(){
	std::cout << "Animal destructor called!" << std::endl;
}

Animal::Animal(const Animal &copy){
	*this = copy;
}

Animal & Animal::operator=(const Animal &copy){
	if (&copy != this) {
		this->~Animal();
		new(this) Animal();
	}
	return (*this);
}

std::string Animal::getType(void) const {
	return (this->type);
}

void Animal::makeSound(void) const {
	std::cout << "Not animals type!" << std::endl;
}
