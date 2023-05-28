/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:52:36 by nlocusso          #+#    #+#             */
/*   Updated: 2023/02/24 10:52:38 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie *Zombie_horde1 = zombieHorde(10, "Nathan");
	Zombie *Zombie_horde2 = zombieHorde(10, "Nathan_v2");

	for (int i = 0; i != 10; i++) {
		std::cout << "Horde 1 Zombie " << i << " ";
		Zombie_horde1[i].announce();
		std::cout << "Horde 2 Zombie " << i << " ";
		Zombie_horde2[i].announce();
	}
	delete [] Zombie_horde1;
	delete [] Zombie_horde2;
	return (0);
}
