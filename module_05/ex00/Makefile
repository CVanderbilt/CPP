SRCS	= main.cpp

SRCS	+= Bureaucrat.cpp

OBJS	= $(SRCS:.cpp=.o)

NAME	= buro0

CC		= clang++

FLAGS	= -Wall -Wextra -Werror

HEADER	= Bureaucrat.hpp




all:	$(NAME)

.PHONY:	clean fclean re bonus bench bclean

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $<  -o $(<:.c=.o)