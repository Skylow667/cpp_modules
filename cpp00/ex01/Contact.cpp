/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:50:06 by nlocusso          #+#    #+#             */
/*   Updated: 2023/02/24 13:36:26 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {
	return ;
}

Contact::~Contact(void) {
	return ;
}

std::string Contact::GetFirstName (void) {
	return (this->first_name);
}

std::string Contact::GetLastName (void) {
	return (this->last_name);
}

std::string Contact::GetNickname (void) {
	return (this->nickname);
}

std::string Contact::GetNumber (void) {
	return (this->phone_number);
}

std::string Contact::GetSecret (void) {
	return (this->darkest_secret);
}

void Contact::AddContact(void) {
	std::cout << "All data of a contact can't be blank :" << std::endl;
	do {
		std::cout << "First Name : ";
		if (!std::getline(std::cin, this->first_name))
			std::exit(1);
	} while (!this->first_name.size());
	do {
		std::cout << "Last Name : ";
		if (!std::getline(std::cin, this->last_name))
			std::exit(1);
	} while (!this->last_name.size());
	do {
		std::cout << "Nickname : ";
		if (!std::getline(std::cin, this->nickname))
			std::exit(1);
	} while (!this->nickname.size());
	do {
		std::cout << "Phone Number : ";
		if (!std::getline(std::cin, this->phone_number))
			std::exit(1);
	} while (!this->phone_number.size());
	do {
		std::cout << "Darkest Secret : ";
		if (!std::getline(std::cin, this->darkest_secret))
			std::exit(1);
	} while (!this->darkest_secret.size());
}

void Contact::PrintContact(void) {
	std::cout << "First Name : " << this->first_name << std::endl;
	std::cout << "Last Name : " << this->last_name << std::endl;
	std::cout << "Nickname : " << this->nickname << std::endl;
	std::cout << "Phone Number : " << this->phone_number << std::endl;
	std::cout << "Darkest Secret : " << this->darkest_secret << std::endl;
}
