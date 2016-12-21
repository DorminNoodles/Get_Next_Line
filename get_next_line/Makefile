NAME = debug
CC =  clang
SRC_DIR =
SRC_NAMES =		get_next_line.c			\
				main.c
FLAGS = -Wall -Wextra -Werror
SRC = $(addprefix $(SRC_DIR), $(SRC_NAMES))
INC = ./
OBJ = $(SRC_NAME:.c=.o)

all : $(NAME)

$(NAME):
	make -C libft/
	$(CC) -g  $(SRC) -I $(INC) libft/libft.a -o $(NAME) $(FLAGS)

clean :
	rm -f $(OBJ)
	@make -C libft/ clean

fclean : clean
	rm -f $(NAME)
	@make -C libft/ fclean

re : fclean all
