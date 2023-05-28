#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(void):ClapTrap() {
}

ScavTrap::ScavTrap(std::string Name):ClapTrap(Name) {
	std::cout << "ScavTrap constructor called" << std::endl;
	HitPoint = 100;
	EnergyPoint = 50;
	AttackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy):ClapTrap(copy) {
	return ;
}

ScavTrap &ScavTrap::operator= (const ScavTrap &copy) {
	if (&copy != this) {
		this->~ScavTrap();
		new(this) ScavTrap(Name);
	}
	return (*this);
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap destructor called" << std::endl;
	return ;
}

void ScavTrap::guardGate(void) {
	if (HitPoint <= 0) {
		std::cout << "ScavTrap " << Name << " is dead, so i can't passed in Gate keeper mode!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << Name << " is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	if (this->HitPoint <= 0) {
		std::cout << this->Name << " is dead, so he can't attack!" <<std::endl;
		return  ;
	}
	if (this->EnergyPoint <= 0) {
		std::cout << this->Name << " as no energy, so he can't attack!" <<std::endl;
		return  ;
	}
	std::cout << "ScavTrap " << this->Name << " attacks " << target;
	std::cout << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
	this->EnergyPoint--;
}
