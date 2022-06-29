CFLAGS = -Wall -Wextra -Werror
LFLAGS = src/mlx/libmlx.a -framework OpenGL -framework AppKit
LFLAGS_BONUS = bonus/mlx/libmlx.a -framework OpenGL -framework AppKit
MLX = src/mlx/libmlx.a
SRCS = $(wildcard src/so_long_utils/*c) $(wildcard src/src/*c)
SRCS_BONUS = $(wildcard bonus/so_long_utils/*c) $(wildcard bonus/src_bonus/*c)
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
NAME = so_long
NAME_BONUS = so_long_bonus

all : $(MLX) $(NAME)

$(MLX) :
	make -sC ./src/mlx

$(NAME) : $(OBJS)
	gcc $(SRCS) $(LFLAGS) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	make -sC ./bonus/mlx
	gcc $(SRCS_BONUS) $(LFLAGS_BONUS) -o $(NAME_BONUS)
clean:
	rm -rf $(OBJS) $(NAME)

fclean:
	rm -rf $(OBJS) $(NAME)
	rm -rf $(OBJS_BONUS) $(NAME_BONUS)
	make clean -C ./src/mlx
	make clean -C ./bonus/mlx

norm:
	norminette ./*.c

re : fclean all

.PHONY: clean fclean re
