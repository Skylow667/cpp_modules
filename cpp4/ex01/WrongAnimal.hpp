#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>
# include <string>

class WrongAnimal
{
	 public:
		WrongAnimal();
		virtual ~WrongAnimal();
		WrongAnimal (const WrongAnimal &copy);
		WrongAnimal &operator=(const WrongAnimal&);
		std::string getType(void) const;
		void makeSound(void) const;
	 protected:
		std::string type;
};

#endif
