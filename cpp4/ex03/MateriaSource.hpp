#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
#include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	 public:
		MateriaSource();
		~MateriaSource();
		MateriaSource (MateriaSource &copy);
		MateriaSource (IMateriaSource &copy);
		MateriaSource &operator=(const MateriaSource&);
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
	 private:
		AMateria* _stock_materia[4];
};

#endif
