CC = gcc
FLAGS = -Wall -Wextra -Werror -c
HEADER = ft_printf.h
LIBFT = libft
LIBFT_LIB = libft.a
RM = rm -rf
NAME = libftprintf.a
srcs = ft_printf.c \
	   ft_printf_utils.c \
	   src/print_percent.c \
	   src/print_c.c \
	   src/print_sp.c \
	   src/print_num.c
objs = $(srcs:.c=.o)


all:$(NAME)

$(NAME):$(objs)
	make all -C $(LIBFT)
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	ar rc $(NAME) $^

%.o:%.c $(HEADER)
	$(CC) $(FLAGS) $< -o $@

clean:
	$(RM) $(objs)
	make clean -C $(LIBFT)

fclean:
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

re:
	fclean all
