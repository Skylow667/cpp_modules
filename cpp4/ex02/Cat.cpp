#include "Cat.hpp"
#include "AAnimal.hpp"
#include "Brain.hpp"

Cat::Cat(void):AAnimal(){
	std::cout << "Cat constructor called!" << std::endl;
	this->type = "Cat";
	_cat_brain = new Brain();
}

Cat::~Cat(){
	std::cout << "Cat destructor called!" << std::endl;
	delete _cat_brain;
}

Cat::Cat(const Cat &copy):AAnimal(copy) {
	*this = copy;
}

Cat & Cat::operator=(const Cat &copy){
	_cat_brain = new Brain(*copy._cat_brain);
	return (*this);
}

void Cat::makeSound(void) const {
	std::cout << "The cat meows!" << std::endl;
}

void Cat::setCatIdeas(std::string ideas) {
	this->_cat_brain->setIdeas(ideas);
}

void Cat::printCatIdeas(void) {
	this->_cat_brain->printIdeas();
}
