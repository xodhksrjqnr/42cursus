NAME = push_swap

CC = gcc

HEAD = includes

FLAG = -Wall -Wextra -Werror -I$(HEAD) -g3 -fsanitize=address

RM = rm -rf

SRCS = srcs/elem.c \
	srcs/setting_program.c \
	srcs/push_swap.c \
	srcs/command.c \
	srcs/sort.c \
	srcs/sort_utils.c \
	srcs/check_end_sort.c \
	srcs/check_start_sort.c

OBJS = $(addprefix objs/, $(subst srcs/, , $(SRCS:.c=.o)))

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAG) $(OBJS) -o $(NAME)

$(OBJS) : $(SRCS)
	$(CC) $(FLAG) -c $(SRCS)
	mv -f *.o objs

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all