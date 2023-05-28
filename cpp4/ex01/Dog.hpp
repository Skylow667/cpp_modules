#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	 public:
		Dog();
		~Dog();
		Dog (const Dog &copy);
		Dog &operator=(const Dog& copy);
		void makeSound(void) const;
		void setDogIdeas(std::string ideas);
		void printDogIdeas(void);
	private:
		Brain *_dog_brain;
};

#endif
