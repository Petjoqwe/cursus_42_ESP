NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = .
LIBFTDIR = libft

SRCS = push_swap.c \
       stack_operations.c \
       stack_utils.c \
       sort_algorithms.c

OBJS = $(SRCS:.c=.o)

LIBFT = $(LIBFTDIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFTDIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re