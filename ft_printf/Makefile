CC = gcc
FLAGS = -Wall -Wextra -Werror -c
NAME = libftprintf.a
srcs = libft/*.c \
	   ft_printf.c \
	   ft_printf_utils.c \
	   src/print_percent.c \
	   src/print_c.c \
	   src/print_sp.c \
	   src/print_num.c

all:$(NAME)

$(NAME):
	$(CC) $(FLAGS) $(srcs)
	ar -rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -f *.o
fclean:
	rm -f $(NAME)
re:
	fclean all
