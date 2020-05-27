SRCS			= cato9tails.cpp main.cpp
OBJS			= $(SRCS:.cpp=.o)

CXX				= clang++
RM				= rm -f
CXXFLAGS		= -Wall -Wextra -Werror -I.

NAME			= cato9tails

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

test:			$(NAME)
				./replace test.txt a "(a)"
				./replace test.txt.replace "(a)" "(A_in_parentheses)"
				./replace test.txt.replace.replace "(A_in_parentheses)" "(-------------------------------------------------LONG-------------------------------------------------)"
				./replace test.txt.replace.replace.replace "(-------------------------------------------------LONG-------------------------------------------------)" a
				

.PHONY:			all clean fclean re test