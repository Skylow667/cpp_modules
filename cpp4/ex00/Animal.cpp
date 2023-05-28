#include "Animal.hpp"

Animal::Animal(void){
	std::cout << "Animal constructor called!" << std::endl;
	this->type = "Animal";
}

Animal::~Animal(){
	std::cout << "Animal destructor called!" << std::endl;
}

Animal::Animal(const Animal &copy){
	this->type = copy.type;
}

Animal & Animal::operator=(const Animal &copy){
	this->type = copy.type;
	return (*this);
}

std::string Animal::getType(void) const {
	return (this->type);
}

void Animal::makeSound(void) const {
	std::cout << "Not animals type!" << std::endl;
}
