#include "Dog.hpp"

Dog::Dog(void):AAnimal(){
	std::cout << "Dog constructor called!" << std::endl;
	this->type = "Dog";
	_dog_brain = new Brain(); 
}

Dog::~Dog(){
	std::cout << "Dog destructor called!" << std::endl;
	delete _dog_brain;
}

Dog::Dog(const Dog &copy):AAnimal(copy){
	*this = copy;
}

Dog & Dog::operator=(const Dog &copy){
	_dog_brain = new Brain(*copy._dog_brain);
	return (*this);
}

void Dog::makeSound(void) const {
	std::cout << "The dog barks!" << std::endl;
}

void Dog::setDogIdeas(std::string ideas) {
	this->_dog_brain->setIdeas(ideas);
}

void Dog::printDogIdeas(void) {
	this->_dog_brain->printIdeas();
}
