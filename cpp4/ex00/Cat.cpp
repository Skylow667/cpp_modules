#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat():Animal(){
	std::cout << "Cat constructor called!" << std::endl;
	this->type = "Cat";
}

Cat::~Cat(){
	std::cout << "Cat destructor called!" << std::endl;
}

Cat::Cat(const Cat &copy):Animal(copy){
}

Cat & Cat::operator=(const Cat &copy){
	this->type = copy.type;
	return (*this);
}

void Cat::makeSound(void) const {
	std::cout << "The cat meows!" << std::endl;
}
