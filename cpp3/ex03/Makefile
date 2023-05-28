# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 17:13:34 by nlocusso          #+#    #+#              #
#    Updated: 2023/02/25 11:42:14 by nlocusso         ###   ########.fr        #
#    Updated: 2023/01/10 15:15:05 by nlocusso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

OBJS		= ${SRCS:.cpp=.o}

NAME		= ./DiamondTrap

COMPILER	= c++

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -std=c++98 

all :        ${NAME}

.cpp.o : $(OBJS)
		$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

${NAME}:	${OBJS}
			${COMPILER} ${CFLAGS} -o ${NAME} ${OBJS}

clean :	
			${RM} ${OBJS} 

fclean : clean
			${RM} ${NAME} 

re :		fclean all

.PHONY : all clean fclean re
