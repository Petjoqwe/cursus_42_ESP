NAME = libft.a

SRC = ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c

OBJ = $(SRC:.c=.o)
CC = cc
$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

all: $(NAME)
.o:.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $<
	
clean:
	rm -f $(OBJ)
fclean: 
	rm -f $(NAME)$(OBJ)

re: fc clean

.PHONY: all bonus clean fclean re
