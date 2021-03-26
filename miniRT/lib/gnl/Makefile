NAME = gnl.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRCS = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJS)

all : $(NAME)	   

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
