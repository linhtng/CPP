CFLAGS = g++ -Wall -Wextra -Werror -std=c++98

NAME = colosseum

SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

OBJ_PATH = ./objects/
OBJ		= $(SRC:.cpp=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: %.cpp
	$(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_PATH) $(OBJS)
	$(CFLAGS) $(OBJS) -o $@
	
clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all
