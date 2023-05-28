#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

WrongCat::WrongCat():WrongAnimal(){
	std::cout << "WrongCat constructor called!" << std::endl;
	this->type = "Animal";
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat destructor called!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy):WrongAnimal(copy){
}

WrongCat & WrongCat::operator=(const WrongCat &copy){
	this->type = copy.type;
	return  (*this);
}

void WrongCat::makeSound(void) const {
	std::cout << "The WrongCat meows!" << std::endl;
}
