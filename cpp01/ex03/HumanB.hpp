/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:53:25 by nlocusso          #+#    #+#             */
/*   Updated: 2023/02/24 10:53:26 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"

class HumanB {
	public:
		HumanB(std::string name);	
		~HumanB(void);
		void attack(void);
		void setWeapon(Weapon& club);
	private:
		Weapon *club;
		std::string name;
};
#endif
