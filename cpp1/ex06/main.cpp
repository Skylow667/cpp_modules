/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:54:30 by nlocusso          #+#    #+#             */
/*   Updated: 2023/02/24 18:28:31 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv) {
	std::string level_str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	Harl HarlFilter;
	int level = -1;

	if (argc != 2) {
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (1);
	}
	for (int i = 0; i != 4; i++)
		if (level_str[i].compare(argv[1]) == 0)
			level = i;
	if (level == -1) {
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (1);
	}
	for (int j = level; j != 4; j++) {
		switch (j) {
			case (0): 
				std::cout << "[ DEBUG ]" << std::endl;
				HarlFilter.complain(level_str[j]);
				break;
			case (1):
				std::cout << "[ INFO ]" << std::endl;
				HarlFilter.complain(level_str[j]);
				break;
			case (2):
				std::cout << "[ WARNING ]" << std::endl;
				HarlFilter.complain(level_str[j]);
				break;
			case (3):
				std::cout << "[ ERROR ]" << std::endl;
				HarlFilter.complain(level_str[j]);
				break;
			default:
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		}
		std::cout << std::endl;
	}
	return (0);
}
