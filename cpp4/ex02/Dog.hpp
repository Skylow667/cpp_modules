#ifndef DOG_HPP
# define DOG_HPP
# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
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
