/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:52:44 by nlocusso          #+#    #+#             */
/*   Updated: 2023/02/24 10:52:45 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>
# include <iostream>

class Zombie {
	public:
		Zombie(void);
		~Zombie(void);
		void announce ( void );
		void SetName(std::string name);
	private:
		std::string name;
};

Zombie* zombieHorde( int N, std::string name );
#endif
