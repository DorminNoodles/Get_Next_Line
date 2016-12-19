NAME = debug
CC =  clang
SRC_DIR = srcs/
SRC_NAMES =		get_next_line.c			\
				main.c

SRC = $(addprefix $(SRC_DIR), $(SRC_NAMES))
INC = includes
OBJ = $(SRC_NAME:.c=.o)

all : $(NAME)

$(NAME):
	make -C libft/
	$(CC) -g  $(SRC) -I $(INC) libft/libft.a -o $(NAME)

clean :
	rm -f $(OBJ)
	@make -C libft/ clean

fclean : clean
	rm -f $(NAME)
	@make -C libft/ fclean

re : fclean all
