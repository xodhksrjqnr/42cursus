NAME = miniRT

HEAD = includes

CC = gcc

FLAGS = -Wall -Wextra -Werror -I $(HEAD)

RM = rm -rf

SRCS = srcs/miniRT.c \
       srcs/set_utils/resolution.c \
       srcs/set_utils/ambient.c \
       srcs/set_utils/camera.c \
       srcs/set_utils/light.c \
       srcs/set_utils/sphere.c \
       srcs/set_utils/plane.c \
       srcs/set_utils/square.c \
       srcs/set_utils/cylinder.c \
       srcs/set_utils/triangle.c \
       srcs/set_utils/list_utils.c \
       srcs/set_utils/set_utils.c \
       srcs/set_utils/get_next_line.c \
       srcs/set_utils/get_next_line_utils.c \
       srcs/vector/vector_basic.c \
       srcs/vector/vector_conversion.c

OBJS = $(SRCS : .c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	    $(CC) $(FLAGS) $(OBJS) ./srcs/libmlx.dylib

clean : $(RM) $(OBJS)

fclean : $(RM) $(NAME)

re : fclean all
