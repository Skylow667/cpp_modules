/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:54:09 by nlocusso          #+#    #+#             */
/*   Updated: 2023/02/24 10:54:10 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void) {
	Harl Harl;

	Harl.complain("DEBUG");
	std::cout << std::endl;
	Harl.complain("INFO");
	std::cout << std::endl;
	Harl.complain("WARNING");
	std::cout << std::endl;
	Harl.complain("ERROR");
	std::cout << std::endl;
	Harl.complain("rfgehjhgf");
}
