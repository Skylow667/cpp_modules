#ifndef AANIMAL_HPP
# define AANIMAL_HPP
# include <string>
# include <iostream>

class AAnimal
{
	 public:
		AAnimal(void);
		virtual ~AAnimal(void);
		AAnimal (const AAnimal &copy);
		AAnimal &operator=(const AAnimal& copy);
		std::string getType(void) const;
		virtual void makeSound(void) const = 0;
	protected:
		std::string type;
};

#endif
