#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "Test 1:" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;
	delete meta;
	delete j;
	delete i;
	std::cout << std::endl;

	std::cout << "Test 2:" << std::endl;
	const WrongAnimal* meta2 = new WrongAnimal();
	const Animal* j2 = new Dog();
	const WrongAnimal* i2 = new WrongCat();
	std::cout << std::endl;

	std::cout << j2->getType() << " " << std::endl;
	std::cout << i2->getType() << " " << std::endl;
	i2->makeSound(); //will output the cat sound!
	j2->makeSound();
	meta2->makeSound();

	std::cout << std::endl;
	delete meta2;
	delete j2;
	delete i2;

	return 0;
}
