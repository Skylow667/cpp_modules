#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	std::cout << "WrongAnimal constructor called!" << std::endl;
	this->type = "Cat";
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal destructor called!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy){
	this->type = copy.type;
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal &copy){
	this->type = copy.type;
	return (*this);
}

std::string WrongAnimal::getType(void) const {
	return (this->type);
}

void WrongAnimal::makeSound(void) const {
	std::cout << "The WrongAnimal no type!" << std::endl;
}
