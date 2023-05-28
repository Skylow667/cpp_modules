#include "Serializer.hpp"

int	main(void)
{
	Data *ptr = new Data;

	uintptr_t int_ptr = Serializer::serialize(ptr);	
	Data *ptr2 = Serializer::deserialize(int_ptr);
	std::cout << ptr << std::endl;
	std::cout << ptr2 << std::endl;
	if (ptr2 != ptr)
		std::cout << "Not the same adress!" << std::endl;
	else
		std::cout << "Same adress!" << std::endl;
	delete ptr;
	return (0);
}
