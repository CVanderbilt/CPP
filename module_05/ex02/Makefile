SRCS	= main.cpp

SRCS	+= Bureaucrat.cpp Form.cpp PresidentialPardonForm.cpp\
			RobotomyRequestForm.cpp ShrubberyCreationForm.cpp

OBJS	= $(SRCS:.cpp=.o)

NAME	= buro2

CC		= clang++

FLAGS	= -Wall -Wextra -Werror

HEADER	= Bureaucrat.hpp Form.hpp PresidentialPardonForm.hpp \
			RobotomyRequestForm.hpp ShrubberyCreationForm.hpp




all:	$(NAME)

.PHONY:	clean fclean re all

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $<  -o $(<:.c=.o)