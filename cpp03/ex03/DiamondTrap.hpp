#ifndef DIAMONDTRAPP_HPP
# define DIAMONDTRAPP_HPP
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {
	 public:
		DiamondTrap(std::string Name);
		~DiamondTrap(void);
		DiamondTrap (const DiamondTrap &copy);
		DiamondTrap &operator=(const DiamondTrap&);
		void whoAmI(void);
		void attack(const std::string &target);
	 private:
	 	DiamondTrap(void);
		std::string _name;	
		using ClapTrap::Name;
};

#endif
