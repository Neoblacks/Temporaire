
NAME = so_long

PATH_LIBFT = libft
LIBFT = $(PATH_LIBFT)/libft.a

PATH_MLX = mlx
MLX = $(PATH_MLX)/libmlx.a -I $(PATH_MLX) -L $(PATH_MLX) -lmlx -lXext -lX11 -lm

PATH_SRCS = srcs

SRCS =  $(PATH_SRCS)/main.c \
		$(PATH_SRCS)/gestion_window.c \
		$(PATH_SRCS)/gestion_map.c \
		$(PATH_SRCS)/gestion_map_utils.c \
		$(PATH_SRCS)/ft_error.c \
		$(PATH_SRCS)/texture.c \
		$(PATH_SRCS)/texture_utils.c \
		$(PATH_SRCS)/check_map.c \
		$(PATH_SRCS)/render.c \
		$(PATH_SRCS)/render_utils.c \
		$(PATH_SRCS)/move.c \
		$(PATH_SRCS)/validate_map.c \
		$(PATH_SRCS)/validate_map_utils.c \
		$(PATH_SRCS)/validate_map_utils2.c \
		$(PATH_SRCS)/end.c \
		$(PATH_SRCS)/end_utils.c \
		$(PATH_SRCS)/next_map.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

RM = rm -f

all: $(LIBFT) $(MLX) $(NAME)

$(NAME): $(OBJS) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(PATH_MLX) -I $(PATH_LIBFT) -I $(PATH_SRCS)

$(LIBFT):
	$(MAKE) -C $(PATH_LIBFT)

$(MLX):
	$(MAKE) -C $(PATH_MLX)

clean:
	$(MAKE) -C $(PATH_LIBFT) clean
	$(MAKE) -C $(PATH_MLX) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(PATH_LIBFT) fclean
	$(MAKE) -C $(PATH_MLX) clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
