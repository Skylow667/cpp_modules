#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap(), ScavTrap(), FragTrap(){
}

DiamondTrap::DiamondTrap(std::string Name): ClapTrap(Name), ScavTrap(Name), FragTrap(Name){
	std::cout << "DiamondTrap constructor called" << std::endl;
	this->_name = Name;
	ClapTrap::Name += "_clap_name";
	HitPoint = FragTrap::HitPoint;
	EnergyPoint = ScavTrap::EnergyPoint;
	AttackDamage = FragTrap::AttackDamage;
	std::cout << EnergyPoint << std::endl;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy):ClapTrap(copy), ScavTrap(copy), FragTrap(copy){
}

DiamondTrap & DiamondTrap::operator=(const DiamondTrap &copy){
	if (&copy != this) {
		this->~DiamondTrap();
		new(this) DiamondTrap(copy.Name);
	}
	return (*this);
}

void DiamondTrap::attack(const std::string &target){
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) {
	if (HitPoint <= 0)
		std::cout << Name << " his dead, so he can't say who he is!" << std::endl;
	else
		std::cout << "Diamond Name: " << _name << " and Clap Name: " << Name << std::endl;
}
