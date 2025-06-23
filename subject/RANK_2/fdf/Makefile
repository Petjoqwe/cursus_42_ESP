NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude -Ilib/MLX42/include
MLX42_DIR = lib/MLX42
MLX42_FLAGS = -L$(MLX42_DIR)/build -lmlx42 -ldl -lglfw -pthread -lm
SRC = src/main.c src/parser.c src/draw.c src/utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(MLX42_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
