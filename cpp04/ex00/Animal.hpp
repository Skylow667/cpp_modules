#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>
# include <iostream>

class Animal
{
	 public:
		Animal(void);
		virtual ~Animal(void);
		Animal (const Animal &copy);
		Animal &operator=(const Animal&);
		std::string getType(void) const;
		virtual void makeSound(void) const;
	protected:
		std::string type;
};

#endif
