NAME = pipex

CC = gcc

HEAD = -I includes

FLAG = -Wall -Wextra -Werror $(HEAD) -g3 -fsanitize=address

SRCS = srcs/main.c

OBJS = $(SRCS:.c=.o)

.c.o :
	$(CC) $(FLAG) -c $< -o $(<:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$