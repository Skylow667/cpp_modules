/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:53:22 by nlocusso          #+#    #+#             */
/*   Updated: 2023/02/24 13:50:04 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	this->name = name;
	this->club = NULL;
}

HumanB::~HumanB(void){
	return ;
}

void	HumanB::attack(void) {
	if (this->club != NULL)
		std::cout << this->name << " attacks with their " << this->club->getType() << std::endl;
	else
		std::cout << this->name << " have no weapon!" << std::endl;
}

void	HumanB::setWeapon(Weapon& club) {
	this->club = &club;
}
