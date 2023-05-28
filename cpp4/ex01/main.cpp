#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"

int main()
{
	Animal *tab_animal[10];

	for (int i = 0; i != 10; i++) {
		if (i % 2 == 0)
			tab_animal[i] = new Cat();
		else
			tab_animal[i] = new Dog();
	}
	for (int i = 0; i != 10; i++) {
		if (i % 2 == 0)
			((Cat*)tab_animal[0])->setCatIdeas("Cat Ideas");
		else 
			((Dog*)tab_animal[1])->setDogIdeas("Dog Ideas");
	}
	((Cat*)tab_animal[0])->printCatIdeas();
	((Dog*)tab_animal[1])->printDogIdeas();
	for (int i = 0; i != 10; i++)
		delete tab_animal[i]; 
	std::cout << std::endl;

	std::cout << "test 2:" << std::endl;
	std::cout << std::endl;
	Cat *cat = new Cat();
	cat->setCatIdeas("Armand le bg");
	cat->printCatIdeas();
	Cat *cat2 = new Cat(*cat);
	delete cat;
	cat2->printCatIdeas();
	delete cat2;
	return 0;
}
