SRCS	= main.cpp

OBJS	= $(SRCS:.cpp=.o)

NAME	= templates

CC		= clang++

FLAGS	= -Wall -Wextra -Werror

HEADER	= Templates.hpp


all:	$(NAME)

.PHONY:			all clean fclean re

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $<  -o $(<:.c=.o)