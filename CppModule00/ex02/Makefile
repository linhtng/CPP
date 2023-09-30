CFLAGS = g++ -Wall -Wextra -Werror -std=c++98

NAME = account

SRC = Account.cpp \
	Account.cpp \
	test.cpp

OBJ_PATH = ./objects/
OBJ		= $(SRC:.cpp=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: %.cpp
	$(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CFLAGS) $(OBJS) -o $@
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
