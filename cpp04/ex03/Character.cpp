#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(std::string name):_name(name){
	for (int i = 0; i != 4; i++) {
		_materia[i] = NULL;
	}
}

Character::Character(){}
Character::~Character(){}

Character::Character(const Character &copy){
	*this = copy;
}

Character & Character::operator=(const Character &copy){
	this->~Character();
	new(this) Character(copy._name);
	for (int i = 0; i != 4; i++)
		this->_materia[i] = copy._materia[i];
	return (*this);
}

std::string const & Character::getName() const {
	return (_name);
}

void Character::equip(AMateria* m) {
	for (int i = 0; i != 4; i++) {
		if (_materia[i] == NULL) {
			_materia[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx) {
	if (idx > 3 || idx < 0) {
		std::cout << "Bad index for unequip the materia!" << std::endl;
		return ;
	}
	_materia[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	(void)target;
	if (idx > 3 || idx < 0) {
		std::cout << "Bad index for using the materia!" << std::endl;
		return ;
	}
	if (_materia[idx] == NULL) {
		std::cout << "The Character has no materia at this index!" << std::endl;
	}
	_materia[idx]->use(target);
	unequip(idx);
}
