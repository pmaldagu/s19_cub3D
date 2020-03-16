NAME = cub3D

CUB = ./map.cub

MLX = ./minilibx/libmlx.a

LIBFT = ./libft/libft.a

SRC =	map.c \
		parsing.c \
		error.c \
		transition.c \
		raycast.c \
		movement.c \
		sprite.c \
		utils.c \
		bmp.c \
		map2merde.c \
		free.c \
		draw.c \
		main.c

BONUS = ./bonus/*.c

FLGS = -Wall -Wextra -Werror -framework OpenGL -framework Appkit

HEADER = ./

FSAN = -g -fsanitize=address

all:
	make -C ./minilibx
	make -C ./libft
	gcc -o $(NAME) -I$(HEADER) $(FSAN) $(FLGS) $(SRC) $(LIBFT) $(MLX)

clean: 
	make -C ./minilibx clean
	make -C ./libft clean
	rm -rf *.o

fclean:
	make -C ./minilibx clean
	make -C ./libft fclean
	rm -rf *.o
	rm -rf ${NAME}

bonus: fclean
	make -C ./minilibx
	make -C ./libft
	gcc -o $(NAME) -I./bonus/ $(FLGS) $(BONUS) $(LIBFT) $(MLX)

re: fclean all

phony: all clean fclean re
