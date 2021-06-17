NAME = pipex

CC = gcc

LIB = libft

HEAD = -I includes -I bonus/includes

FLAG = -Wall -Wextra -Werror $(HEAD) -g3 -fsanitize=address

SRCS = srcs/main.c \
	srcs/pipe_utils.c

BONUS_SRCS = bonus/srcs/main_bonus.c \
	bonus/srcs/pipe_utils_bonus.c

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

.c.o :
	$(CC) $(FLAG) -c $< -o $(<:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(RM) $(BONUS_OBJS)
	make -C $(LIB)
	cp $(LIB)/libft.a libft.a
	$(CC) $(FLAG) $(OBJS) libft.a -o $(NAME)

bonus : $(BONUS_OBJS)
	$(RM) $(OBJS)
	make -C $(LIB)
	cp $(LIB)/libft.a libft.a
	$(CC) $(FLAG) $(BONUS_OBJS) libft.a -o $(NAME)

clean :
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean : clean
	make clean -C $(LIB)
	$(RM) $(NAME) $(OBJS) $(BONUS_OBJS) libft.a

re : fclean all