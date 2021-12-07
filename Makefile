SRC = main.c \
		./gnl/gnl.c \
		./gnl/gnl_utils.c \
		./lib/lib.c \
		./moove/exit.c \
		./moove/moov.c \
		./moove/moove_bis.c \
		./moove/write.c \
		./parsing/error.c \
		./parsing/error2.c \
		./parsing/fill_tab.c \
		./put_img/init_img.c \
		./put_img/put.c \
		./put_img/put_img.c

OBJ = ${SRC:.c=.o}

FLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -L./mlx -L./mlx -lmlx -lXext -lX11

.c.o:
	gcc $(FLAGS) -c $< -o $(<:.c=.o)

NAME = so_long

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(MLX_FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re
