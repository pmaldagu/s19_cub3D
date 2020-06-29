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
		map_zero.c \
		free.c \
		draw.c \
		main.c

BONUS = ./bonus/*.c

FLGS = -Wall -Wextra -Werror

HEADER = ./

FSAN = -g -fsanitize=address

all:
	make -C ./minilibx
	make -C ./libft
	gcc $(NAME) -I$(HEADER) $(FLGS) $(SRC) $(LIBFT) $(MLX) -lm -lX11 -lXext

clean: 
	make -C ./minilibx clean
	make -C ./libft clean
	rm -rf *.o

fclean:
	make -C ./minilibx clean
	make -C ./libft fclean
	rm -rf *.o
	rm -rf *.bmp
	rm -rf ${NAME}

bonus: fclean
	make -C ./minilibx
	make -C ./libft
	gcc $(NAME) -I./bonus/ $(FLGS) $(BONUS) $(LIBFT) $(MLX) -lm -lX11 -lXext

re: fclean all

phony: all clean fclean re
