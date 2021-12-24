NAME = philo

CC = gcc

HEAD = -I includes

FLAG = -Wall -Wextra -Werror $(HEAD) -g3 -fsanitize=address

SRCS = srcs/main.c \
	srcs/setting.c \
	srcs/running.c

OBJS = $(SRCS:.c=.o)

.c.o :
	$(CC) $(FLAG) -c $< -o $(<:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAG) $(OBJS) -o $(NAME)

clean :
	$(RM) $(OBJS) #$(BONUS_OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all