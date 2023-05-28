#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <typeinfo>

Base* generate(void) {
	std::srand(time(NULL));
	int nb = std::rand() % 3;
	if (nb == 0) {
		std::cout << "The random class is A." << std::endl;
		return (new A);
	}
	if (nb == 1) {
		std::cout << "The random class is B." << std::endl;
		return (new B);
	}
	if (nb == 2) {
		std::cout << "The random class is C." << std::endl;
		return (new C);
	}
	return (NULL);
}

void identify(Base* p) {
	Base *typeA = dynamic_cast<A*>(p);
	if (typeA != NULL)
		std::cout << "The type pointed by p is : A" << std::endl;
	Base *typeB = dynamic_cast<B*>(p);
	if (typeB != NULL)
		std::cout << "The type pointed by p is : B" << std::endl;
	Base *typeC = dynamic_cast<C*>(p);
	if (typeC != NULL)
		std::cout << "The type pointed by p is : C" << std::endl;
	return ;
}

void identify(Base& p) {
	try {
		Base &typeA = dynamic_cast<A&>(p);
		(void)typeA;
		std::cout << "The type pointed by p is : A" << std::endl;
		return ;
	}
	catch (std::bad_cast &typeA) {}
	try {
		Base &typeB = dynamic_cast<B&>(p);
		(void)typeB;
		std::cout << "The type pointed by p is : B" << std::endl;
		return ;
	}
	catch (std::bad_cast &typeB) {}
	try {
		Base &typeC = dynamic_cast<C&>(p);
		(void)typeC;
		std::cout << "The type pointed by p is : C" << std::endl;
		return ;
	}
	catch (std::bad_cast &typeC) {}
	return ;
}

int	main(void)
{
	Base *ptr = generate();

	identify(ptr);
	identify(*ptr);
	delete ptr;
	return (0);
}
