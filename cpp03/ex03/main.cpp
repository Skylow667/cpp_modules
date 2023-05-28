#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void) {
	ScavTrap Scav1("Scav1");
	FragTrap Frag1("Frag1");
	DiamondTrap Diamond1("Diam1");
	std::cout << std::endl;

	Diamond1.whoAmI();
	Diamond1.attack(Frag1.getName());
	Frag1.takeDamage(Diamond1.getAttackDamage());
	Frag1.attack(Scav1.getName());
	Scav1.takeDamage(Frag1.getAttackDamage());
	Frag1.highFivesGuys();
	Scav1.attack(Frag1.getName());
	Frag1.takeDamage(Scav1.getAttackDamage());
	Scav1.guardGate();

	std::cout << std::endl;
}
