#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap Bot1("Bot1");
	ClapTrap Bot2("Bot2");

	Bot1.attack(Bot2.getName());
	Bot2.takeDamage(Bot1.getAttackDamage());

	Bot2.takeDamage(6);
	Bot2.beRepaired(2);
	Bot2.takeDamage(6);
	Bot2.beRepaired(2); //Error because no more healt point
	Bot2.takeDamage(6); //Error because no more healt point
}
