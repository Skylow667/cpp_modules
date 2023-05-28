CC=c++
NAME = convert
SRCS = main.cpp ScalarConverter.cpp
HEADER = ScalarConverter.hpp
OBJS = $(SRCS:.cpp=.o)
CFLAGS = -Wall -Wextra -Werror --std=c++98 -g
LDFLAGS = 

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o : %.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJS)

run: all
	./$(NAME)

run2: all
	valgrind --show-leak-kinds=all --leak-check=full ./$(NAME)

re: fclean all

.PHONY: all fclean clean run run2 re
