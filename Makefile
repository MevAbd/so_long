SRC = main.c $(wildcard gnl/*.c) $(wildcard lib/*.c) $(wildcard parsing/*.c) $(wildcard put_img/*.c) $(wildcard moov/*.c)

OBJ = ${SRC:.c=.o}

FLAGS = -Wall -Wextra -Werror -fsanitize=address

MLX_FLAGS = -L./mlx -L./mlx -lmlx -lXext -lX11
#MLX_FLAGS = -L/usr/X11/lib -L/usr/local/lib -lmlx -lXext -lX11

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
