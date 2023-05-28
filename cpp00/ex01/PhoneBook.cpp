/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:50:37 by nlocusso          #+#    #+#             */
/*   Updated: 2023/02/24 13:34:16 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cctype>
#include <cstdlib>
#include <iomanip>

PhoneBook::PhoneBook(void) {
	return ;
}

PhoneBook::~PhoneBook(void) {
	return ;
}

Contact &PhoneBook::getContact(int i) {
	return (this->_Contact[i]);
}

void PhoneBook::PrintPhoneBook(void) {
	std::string str;
	std::string new_first_name;
	std::string new_last_name;
	std::string new_nickname;
	int index = 8;

	std::cout << std::setw(10) << std::right;
	std::cout << "Index" << "|";
	std::cout << std::setw(10) << std::right;
	std::cout << "First Name" << "|";
	std::cout << std::setw(10) << std::right;
	std::cout << "Last Name" << "|";
	std::cout << std::setw(10) << std::right;
	std::cout << "Nickname" << std::endl;
	for (int i = 0; i != 8; i++) {
		std::cout << std::setw(10) << std::right;
		std::cout << i << "|";
		std::cout << std::setw(10) << std::right;
		if (this->_Contact[i].GetFirstName().size() > 10)
			std::cout << this->_Contact[i].GetFirstName().substr(0, 9) + "." << "|";
		else
			std::cout << this->_Contact[i].GetFirstName().substr(0, 10) << "|";
		std::cout << std::setw(10) << std::right;
		if (this->_Contact[i].GetLastName().size() > 10)
			std::cout << this->_Contact[i].GetLastName().substr(0, 9) + "." << "|";
		else
			std::cout << this->_Contact[i].GetLastName().substr(0, 10) << "|";
		std::cout << std::setw(10) << std::right;
		if (this->_Contact[i].GetNickname().size() > 10)
			std::cout << this->_Contact[i].GetNickname().substr(0, 9) + "." << std::endl;
		else
			std::cout << this->_Contact[i].GetNickname().substr(0, 10) << std::endl;
	}
	while (index > 7) {
		do {
			std::cout << "Choose a contact index between 0 and 7 : ";
			if (!std::getline(std::cin, str))
				std::exit(1);
		} while (str.size() != 1);
		index = std::atoi(str.c_str());
	}
	this->_Contact[index].PrintContact();
}
