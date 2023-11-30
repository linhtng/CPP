CFLAGS = c++ -Wall -Wextra -Werror -std=c++98 -Iincludes -g3
# DEBUG = -fsanitize=address

NAME = Intern

SRC = main.cpp \
	Bureaucrat.cpp \
	AForm.cpp \
	PresidentialPardonForm.cpp \
	RobotomyRequestForm.cpp \
	ShrubberyCreationForm.cpp \
	Intern.cpp

OBJ_PATH = objects/
OBJ		= $(SRC:.cpp=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))

SRCFD = sources/
SRCS	= $(addprefix $(SRCFD), $(SRC))

all: $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRCFD)%.cpp
	$(CFLAGS) $(DEBUG) -c $< -o $@

$(NAME): $(OBJ_PATH) $(OBJS)
	$(CFLAGS) $(OBJS) $(DEBUG) -o $@
	
clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all
