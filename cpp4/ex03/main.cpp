#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;


	std::cout << "\nTest 2:" << std::endl;
	IMateriaSource* materia = new MateriaSource();
	materia->learnMateria(new Ice());
	materia->learnMateria(new Cure());

	ICharacter* character = new Character("character");

	AMateria* test;
	test = materia->createMateria("ice");
	character->equip(test);
	test = materia->createMateria("cure");
	character->equip(test);
	test = materia->createMateria("cure");
	character->equip(test);
	test = materia->createMateria("ice");
	character->equip(test);

	ICharacter* nathan = new Character("Sard");

	character->use(0, *nathan);
	character->use(1, *nathan);
	character->use(2, *nathan);
	character->use(3, *nathan);

	test = materia->createMateria("cure");
	character->equip(test);
	test = materia->createMateria("ice");
	character->equip(test);
	test = materia->createMateria("ice");
	character->equip(test);
	test = materia->createMateria("cure");
	character->equip(test);
	test = materia->createMateria("cure");
	character->equip(test);

	std::cout << std::endl;
	character->use(0, *character);
	character->use(1, *character);
	character->use(2, *character);
	character->use(3, *character);

	delete nathan;
	delete character;
	delete materia;
	return 0;
}
