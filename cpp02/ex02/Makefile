# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlocusso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/26 17:13:34 by nlocusso          #+#    #+#              #
#    Updated: 2023/02/24 16:06:50 by nlocusso         ###   ########.fr        #
#    Updated: 2023/01/10 15:15:05 by nlocusso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= main.cpp Fixed.cpp 

OBJS		= ${SRCS:.cpp=.o}

NAME		= ./a.out

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
