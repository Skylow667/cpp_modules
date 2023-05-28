#include "AAnimal.hpp"

AAnimal::AAnimal(void){
	std::cout << "Animal constructor called!" << std::endl;
	this->type = "Animal";
}

AAnimal::~AAnimal(){
	std::cout << "Animal destructor called!" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy){
	*this = copy;
}

AAnimal & AAnimal::operator=(const AAnimal &copy){
	this->type = copy.type;
	return (*this);
}

std::string AAnimal::getType(void) const {
	return (this->type);
}

void AAnimal::makeSound(void) const {
	std::cout << "Not animals type!" << std::endl;
}
