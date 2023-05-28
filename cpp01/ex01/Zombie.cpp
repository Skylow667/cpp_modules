/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:52:40 by nlocusso          #+#    #+#             */
/*   Updated: 2023/02/24 10:52:41 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) {
	return ;
}

Zombie::~Zombie(void) {
	std::cout << this->name << ": is dead" << std::endl;
	return ;
}

void	Zombie::announce(void) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..."  << std::endl;
}

void	Zombie::SetName(std::string name) {
	this->name = name;
}
