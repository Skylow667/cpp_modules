#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) {
	_type = type;
}

AMateria::~AMateria(){
}

AMateria::AMateria(const AMateria &copy){
	*this = copy;
}

AMateria & AMateria::operator=(const AMateria &copy){
	if (&copy != this)
		_type = copy._type;
	return (*this);
}

std::string const & AMateria::getType(void) const {
	return (_type);
}

std::string AMateria::getType() {
	return (_type);
}

void AMateria::use(ICharacter &target) {
	(void)target;
	std::cout << "No materia type!" << std::endl;
}
