NAME		:= Identify

CPPFLAGS	:= -Wall -Wextra -Werror -std=c++98

CXX			:= c++
RM			:= rm -rf

SRC			:= Base.cpp main.cpp
OBJ			:= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re