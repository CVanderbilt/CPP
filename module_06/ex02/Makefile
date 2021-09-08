SRCS	= main.cpp

SRCS	+= A.cpp B.cpp C.cpp Base.cpp

OBJS	= $(SRCS:.cpp=.o)

NAME	= serializer

CC		= clang++

FLAGS	= -Wall -Wextra -Werror

HEADER	= A.hpp B.hpp C.hpp Base.hpp




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