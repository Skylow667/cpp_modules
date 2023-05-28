#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(void):ClapTrap() {
}

ScavTrap::ScavTrap(std::string Name):ClapTrap(Name) {
	std::cout << "ScavTrap constructor called" << std::endl;
	this->Name = Name;
	HitPoint = 100;
	EnergyPoint = 50;
	AttackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap &copy):ClapTrap(copy) {
	return ;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap destructor called" << std::endl;
	return ;
}

ScavTrap &ScavTrap::operator= (const ScavTrap &copy) {
	if (&copy != this) {
		this->~ScavTrap();
		new(this) ScavTrap(copy.Name);
	}
	return (*this);
}

void ScavTrap::guardGate(void) {
	if (this->getHitPoint() <= 0) {
		std::cout << "ScavTrap " << this->getName() << " is dead, so i can't passed in Gate keeper mode!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	if (getHitPoint() <= 0) {
		std::cout << this->getName() << " is dead, so he can't attack!" <<std::endl;
		return  ;
	}
	if (getEnergyPoint() <= 0) {
		std::cout << this->getName() << " as no energy, so he can't attack!" <<std::endl;
		return  ;
	}
	std::cout << "ScavTrap " << this->getName() << " attacks " << target;
	std::cout << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
	EnergyPoint--;
}
