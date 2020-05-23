SRCS			= srcs/DecrementPtr.cpp srcs/DecrementVal.cpp srcs/IncrementPtr.cpp srcs/IncrementVal.cpp \
					srcs/PutChar.cpp srcs/GetChar.cpp srcs/WhileOpen.cpp srcs/WhileClose.cpp srcs/MindSetProgram.cpp \
					srcs/main.cpp
OBJS			= $(SRCS:.cpp=.o)

CXX				= clang++
RM				= rm -f
CXXFLAGS		= -Wall -Wextra -Werror -I.

NAME			= MindOpenCompiler

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)


.PHONY:			all clean fclean re test