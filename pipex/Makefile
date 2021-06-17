NAME = pipex

CC = gcc

LIB = libft

HEAD = -I includes

FLAG = -Wall -Wextra -Werror $(HEAD) -g3 -fsanitize=address

SRCS = srcs/main.c \
	srcs/pipe_utils.c \
	srcs/check_cmd.c

OBJS = $(SRCS:.c=.o)

.c.o :
	$(CC) $(FLAG) -c $< -o $(<:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIB)
	cp $(LIB)/libft.a libft.a
	$(CC) $(FLAG) $(OBJS) libft.a -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	make clean -C $(LIB)
	$(RM) $(NAME) $(OBJS) libft.a

re : fclean all