/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:50:25 by nlocusso          #+#    #+#             */
/*   Updated: 2023/02/24 13:35:39 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>
# include <iostream>
# include <cstdlib>

class Contact {
	public:
	Contact(void);
	~Contact(void);
	void AddContact(void);
	void PrintContact(void);
	std::string GetFirstName(void);
	std::string GetLastName(void);
	std::string GetNickname(void);
	std::string GetNumber(void);
	std::string GetSecret(void);

	private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
};

#endif
