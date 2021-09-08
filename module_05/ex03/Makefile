SRCS	= main.cpp

SRCS	+= Bureaucrat.cpp Form.cpp PresidentialPardonForm.cpp\
			RobotomyRequestForm.cpp ShrubberyCreationForm.cpp\
			Intern.cpp

OBJS	= $(SRCS:.cpp=.o)

NAME	= buro3

CC		= clang++

FLAGS	= -Wall -Wextra -Werror

HEADER	= Bureaucrat.hpp Form.hpp PresidentialPardonForm.hpp \
			RobotomyRequestForm.hpp ShrubberyCreationForm.hpp \
			Intern.hpp




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