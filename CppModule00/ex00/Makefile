CFLAGS = g++ -Wall -Wextra -Werror -std=c++98

NAME = megaphone

SRC = megaphone.cpp
OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CFLAGS) $(OBJS) -o $@

%.o: %.cpp
	$(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
