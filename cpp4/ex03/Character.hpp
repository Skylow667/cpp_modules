#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"

class Character : public ICharacter
{
	 public:
		Character(std::string name);
		Character();
		~Character();
		Character (const Character &copy);
		Character &operator=(const Character&);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
	 private:
		const std::string _name;
		AMateria* _materia[4];	
		
};

#endif
