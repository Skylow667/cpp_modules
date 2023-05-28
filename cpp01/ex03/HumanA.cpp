/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:53:14 by nlocusso          #+#    #+#             */
/*   Updated: 2023/02/24 10:53:15 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon& club) {
	this->name = name;
	this->club = &club;
}

HumanA::~HumanA(void) {
	return ;
}

void	HumanA::attack(void) {
	std::cout << this->name << " attacks with their " << this->club->getType() << std::endl;
}
