/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:49:35 by nlocusso          #+#    #+#             */
/*   Updated: 2023/02/24 10:49:41 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <string>
#include <iostream>
#include <algorithm>

int	main(int argc, char **argv) {
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i != argc; i++)
	{
		for (int j = 0; argv[i][j]; j++)
		{
			argv[i][j] = std::toupper(argv[i][j]);
			std::cout << argv[i][j];
		}
	}
	std::cout << std::endl;
	return (0);
}
