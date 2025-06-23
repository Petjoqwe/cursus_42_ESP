NAME = fdf_test
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3 -I./MLX42/include -I./MLX42/include/MLX42
LDFLAGS = -L./MLX42 -lmlx42 -lglfw -ldl -lGL -lpthread -lm
RM = rm -f

SRC = main.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
