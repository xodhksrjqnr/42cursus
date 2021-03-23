NAME = miniRT

HEAD = include

CC = gcc

FLAGS = -Wall -Wextra -Werror -I $(HEAD)

RM = rm -rf

SRCS = windows.c

OBJS = $(SRCS : .c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	    $(CC) $(FLAGS) $(OBJS)

clean : $(RM) $(OBJS)

fclean : $(RM) $(NAME)

re : fclean all
