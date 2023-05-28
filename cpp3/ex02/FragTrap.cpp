#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap(void):ClapTrap(){
}

FragTrap::FragTrap(std::string name):ClapTrap(name){
	std::cout << "FragTrap constructor called" << std::endl;
	HitPoint = 100;
	EnergyPoint = 100;
	AttackDamage = 30;
}

FragTrap::~FragTrap(void){
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy):ClapTrap(copy){
	return ;
}

FragTrap & FragTrap::operator=(const FragTrap &copy){
	if (&copy != this) {
		this->~FragTrap();
		new(this) FragTrap(Name);
	}
	return (*this);
}

void FragTrap::highFivesGuys(void) {
	std::cout << Name << " want a high fives." << std::endl;
}
