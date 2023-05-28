/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:53:02 by nlocusso          #+#    #+#             */
/*   Updated: 2023/02/24 10:53:03 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void) {
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Address of the string: "<< &str << std::endl;
	std::cout << "Address of the string held by stringPTR: "<< stringPTR << std::endl;
	std::cout << "Address of the string held by stringREF: "<< &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "Value of the string: " << str << std::endl;
	std::cout << "Value of the string pointed by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value of the string pointed by stringREF: " << stringREF << std::endl;
	return (0);
}
