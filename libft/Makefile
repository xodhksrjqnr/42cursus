NAME=libft.a

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -rf

SRC=$(wildcard *.c)

OBJ=$(SRC:.c=.o)

$(NAME): libft.h
	$(CC) $(CFLAGS) -c $(SRC) libft.h
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean
