#include "Dog.hpp"
#include "Cat.hpp"
#include "AAnimal.hpp"

int main()
{
	AAnimal *tab_animal[10];

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

	std::cout << std::endl << "Test 2" << std::endl;
	Dog *dog = new Dog();
    dog->setDogIdeas("Armand le bg");
    dog->printDogIdeas();
    Dog *dog2 = new Dog(*dog);
    delete dog;
    dog2->printDogIdeas();
	delete dog2;

	return 0;
}
