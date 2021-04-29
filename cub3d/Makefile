NAME = cub3d

CC = gcc

HEAD = includes

FLAG = -Wall -Wextra -Werror -I$(HEAD) -g3 -fsanitize=address

RM = rm -rf

SRCS = srcs/cub3d.c \
	srcs/raycasting/player.c \
	srcs/raycasting/raycasting.c \
	srcs/raycasting/map.c \
	srcs/raycasting/key.c \
	srcs/raycasting/image.c \
	srcs/parse/parse.c \
	srcs/parse/parse_utils_basic.c \
	srcs/parse/identifier/parse_identifier.c \
	srcs/parse/map/parse_map.c \
	srcs/parse/map/parse_map_utils.c \
	srcs/parse/get_next_line/get_next_line.c \
	srcs/parse/get_next_line/get_next_line_utils.c \
	srcs/error_check/error_check.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)

$(OBJS) : $(SRCS)
	$(CC) $(FLAG) $(SRCS) libmlx.dylib

clean :
	$(RM) $(NAME)

fclean :
	$(RM) $(OBJS)

re : fclean all