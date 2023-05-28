/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:53:52 by nlocusso          #+#    #+#             */
/*   Updated: 2023/02/25 10:56:04 by nlocusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

void	ft_sed(std::string file, std::string s1, std::string s2) {
	std::fstream in;

	in.open(file.c_str(), std::ios::in);
	if (!in) {
		std::cout << "Infile cannot be open" << std::endl;
		return ;
	}
	std::fstream out;
	out.open((file + ".replace").c_str(), std::ios::out);
	if (!out) {
		std::cout << "Outfile cannot be create or open" << std::endl;
		return ;
	}
	std::string text;
	std::string tmp;
	while (std::getline(in, text)) {
		size_t	i = 0;
		size_t	pos = text.find(s1);
		tmp.clear();
		while (text[i]) {
			while (i != pos && text[i]) {
				tmp += text[i];
				i++;
			}
			if (!text[i])
				break ;
			tmp += s2;
			pos = text.find(s1, pos + 1);
			i += s1.size();
		}
		out << tmp << std::endl;
	}
	in.close();
	out.close();
}

int	main(int argc, char **argv) {
	if (argc != 4)
		return (1);
	ft_sed(argv[1], argv[2], argv[3]);
	/*test :
	 ft_sed("main.cpp", "out", "in");
	 ft_sed("Makefile", "OBJS", "ob");
	 */
}
