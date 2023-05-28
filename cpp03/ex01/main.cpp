#include "ScavTrap.hpp"

int	main(void) {
	ScavTrap Scav1("Scav1");
	ScavTrap Scav2("Scav2");
	std::cout << std::endl;

	Scav1.attack(Scav2.getName());
	Scav2.takeDamage(Scav1.getAttackDamage());
	Scav2.takeDamage(40);
	Scav2.takeDamage(50);
	Scav2.guardGate();
	Scav1.guardGate();

	Scav2 = Scav1;

	Scav2.guardGate();
	std::cout << std::endl;
}
