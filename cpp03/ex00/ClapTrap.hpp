#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <string>
# include <iostream>

class ClapTrap {
	public:
		ClapTrap(std::string Name);
		ClapTrap(ClapTrap &copy);
		ClapTrap &operator= (ClapTrap &copy);
		~ClapTrap(void);
		std::string getName(void);
		int	getAttackDamage(void);
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	private:
		ClapTrap(void);
		std::string Name;
		int HitPoint;
		int EnergyPoint;
		int AttackDamage;
};
#endif
