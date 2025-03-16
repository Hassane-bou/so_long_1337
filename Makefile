CC = cc
CFLAGS = -Wall -Wextra -Werror 
SRCS =./get_next_line/get_next_line.c  ./get_next_line/get_next_line_utils.c  ./mandatory/so_long.c ./mandatory/utils.c\
		./mandatory/checker_element.c ./mandatory/checker_map.c ./mandatory/checker_path.c ./mandatory/flood_fill.c ./mandatory/free_allocate.c\
		./mandatory/move_player.c ./mandatory/parse.c ./mandatory/read_map.c ./mandatory/put_img.c

SRC_PRINTF = printf/ft_hexa.c printf/ft_printf.c printf/ft_putchar.c \
		printf/ft_putnbr.c printf/ft_putnbruns.c printf/ft_putstr.c

OBJS=$(SRCS:.c=.o) $(SRC_PRINTF:.c=.o)

NAME = so_long
MLX_DIR = ./mlx
MLX_LIB=$(MLX_DIR)/libmlx.a

all : $(MLX_LIB) $(NAME)

$(MLX_LIB):
	make -C $(MLX_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c ./mandatory/so_long.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean