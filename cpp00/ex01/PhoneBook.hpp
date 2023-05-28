/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:50:40 by nlocusso          #+#    #+#             */
/*   Updated: 2023/02/24 13:12:28 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <string>

class PhoneBook {
	public:
	PhoneBook(void);
	~PhoneBook(void);
	void PrintPhoneBook(void);
	Contact &getContact(int i);

	private:
	Contact _Contact[8];
};

#endif
