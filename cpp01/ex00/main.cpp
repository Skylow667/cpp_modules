/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:52:10 by nlocusso          #+#    #+#             */
/*   Updated: 2023/02/24 10:52:12 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie *Zombie1 = newZombie("Nathan");
	Zombie *Zombie2 = newZombie("Louis");

	Zombie1->announce();
	randomChump("Antho");
	Zombie2->announce();
	delete Zombie1;
	delete Zombie2;
}
