/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:50:30 by nlocusso          #+#    #+#             */
/*   Updated: 2023/02/24 13:11:42 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int	main(void)
{
	int	i = 0;
	PhoneBook PhoneBook;	
	std::string str;

	std::cout << "PhoneBook : ";
	while (std::getline(std::cin, str) && str != "EXIT")
	{
		if (str == "ADD")
		{
			PhoneBook.getContact(i).AddContact();
			i++;
			if (i > 7)
				i = 0;
		}
		else if (str == "SEARCH")
			PhoneBook.PrintPhoneBook();
		std::cout << "PhoneBook : ";
	}
	return (0);
}
