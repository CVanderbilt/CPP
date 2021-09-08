SRCS	= main.cpp

SRCS	+= Bureaucrat.cpp

OBJS	= $(SRCS:.cpp=.o)

NAME	= buro0

CC		= clang++

FLAGS	= -Wall -Wextra -Werror

HEADER	= Bureaucrat.hpp




all:	$(NAME)

.PHONY:	clean fclean re all

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $<  -o $(<:.c=.o)