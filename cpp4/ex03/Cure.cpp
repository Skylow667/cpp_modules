#include "Cure.hpp"

Cure::Cure(void):AMateria("cure"){
}

Cure::~Cure(){
}

Cure::Cure(const Cure &copy):AMateria(copy){
}

Cure & Cure::operator=(const Cure &copy){
	if (&copy != this)
	{
		this->~Cure();
		new(this) Cure();
	}
	return (*this);
}

AMateria* Cure::clone() const {
	return (new Cure(*this));
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
