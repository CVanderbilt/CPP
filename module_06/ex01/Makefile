SRCS	= main.cpp

SRCS	+= Data.cpp

OBJS	= $(SRCS:.cpp=.o)

NAME	= serializer

CC		= clang++

FLAGS	= -Wall -Wextra -Werror

HEADER	= Data.hpp




all:	$(NAME)

.PHONY:			all clean fclean re

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $<  -o $(<:.c=.o)