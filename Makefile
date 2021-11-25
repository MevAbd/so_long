SRC = main.c $(wildcard gnl/*.c) $(wildcard lib/*.c)

OBJ = ${SRC:.c=.o}

FLAGS = -Wall -Wextra -Werror #-L/usr/X11/lib -L/usr/local/lib -lmlx -lXext -lX11

.c.o:
	gcc $(FLAGS) -c $< -o $(<:.c=.o)

NAME = so_long

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re