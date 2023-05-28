#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource(){
	for (int i = 0; i != 4; i++)
		_stock_materia[i] = NULL;
}

MateriaSource::~MateriaSource(){
	for (int i = 0; i != 4; i++) {
		if (_stock_materia[i] != NULL)
			delete _stock_materia[i];
	}
}

MateriaSource::MateriaSource(MateriaSource &copy){
	*this = copy;
}

MateriaSource & MateriaSource::operator=(const MateriaSource &copy){
	for (int i = 0; i != 4; i++)
		_stock_materia[i] = copy._stock_materia[i]->clone();
	return (*this);
}

void MateriaSource::learnMateria(AMateria* stock) {
	static int i = 0;

	_stock_materia[i] = stock;
	i++;
	if (i == 4)
		i = 0;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i != 4; i++) {
		if (_stock_materia[i] && _stock_materia[i]->getType() == type)
			return (_stock_materia[i]);
	}
	return (0);
}
