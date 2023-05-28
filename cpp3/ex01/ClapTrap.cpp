#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {
}

ClapTrap::ClapTrap(std::string Name) {
	std::cout << "ClapTrap constructor called" << std::endl;
	this->Name = Name;
	HitPoint = 10;
	EnergyPoint = 10;
	AttackDamage = 0;
	return ;
}

ClapTrap::ClapTrap(ClapTrap &copy) {
	this->Name = copy.Name;
	this->HitPoint = copy.HitPoint;
	this->EnergyPoint = copy.EnergyPoint;
	this->AttackDamage = copy.AttackDamage;
	return ;
}

ClapTrap &ClapTrap::operator= (ClapTrap &copy) {
	this->Name = copy.Name;
	this->HitPoint = copy.HitPoint;
	this->EnergyPoint = copy.EnergyPoint;
	this->AttackDamage = copy.AttackDamage;
	return (*this);
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Claptrap destructor called" << std::endl;
	return ;
}

int	ClapTrap::getAttackDamage(void) {
	return (this->AttackDamage);
}

int	ClapTrap::getEnergyPoint(void) {
	return (this->EnergyPoint);
}

int	ClapTrap::getHitPoint(void) {
	return (this->HitPoint);
}

std::string ClapTrap::getName(void) {
	return (this->Name);
}

void ClapTrap::attack(const std::string &target) {
	if (this->HitPoint <= 0) {
		std::cout << this->Name << " is dead, so he can't attack!" <<std::endl;
		return  ;
	}
	if (this->EnergyPoint <= 0) {
		std::cout << this->Name << " as no energy, so he can't attack!" <<std::endl;
		return  ;
	}
	std::cout << "ClapTrap " << this->Name << " attacks " << target;
	std::cout << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
	this->EnergyPoint--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->HitPoint <= 0) {
		std::cout << this->Name << " is dead, so he can't be attacked!" <<std::endl;
		return  ;
	}
	std::cout << this->Name << " take " << amount << " points of damages!" << std::endl;;
	this->HitPoint -= amount;
	if (this->HitPoint <= 0)
		std::cout << this->Name << " died!" <<std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->HitPoint <= 0) {
		std::cout << this->Name << " is dead, so he can't be repaired!" <<std::endl;
		return  ;
	}
	if (this->EnergyPoint <= 0) {
		std::cout << this->Name << " as no energy, so he can't be repaired!" <<std::endl;
		return  ;
	}
	this->HitPoint += amount;
	this->EnergyPoint--;
}
