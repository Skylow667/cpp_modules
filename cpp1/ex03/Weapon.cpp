/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:53:34 by nlocusso          #+#    #+#             */
/*   Updated: 2023/02/24 18:20:45 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	this->type = type;
}

Weapon::Weapon(void) {
	return ;
}

Weapon::~Weapon(void) {
	return ;
}

std::string &Weapon::getType(void) {
	return (type);
}

void	Weapon::setType(std::string new_type) {
	this->type = new_type;
}
