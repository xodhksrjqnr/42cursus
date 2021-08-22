# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taewan <taewan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/22 19:36:52 by taewan            #+#    #+#              #
#    Updated: 2021/08/22 19:37:00 by taewan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc

LIB = libft

HEAD = -I includes -I bonus/includes

FLAG = -Wall -Wextra -Werror $(HEAD) -g3 -fsanitize=address

SRCS = srcs/pipex.c \
	srcs/error/error.c \
	srcs/init/init.c \
	srcs/init/init_info.c \
	srcs/free/free.c \
	srcs/run/run_program.c \
	srcs/run/pipe_utils.c \
	srcs/validation/invalid.c

BONUS_SRCS = bonus/srcs/pipex_bonus.c \
	bonus/srcs/error/error_bonus.c \
	bonus/srcs/init/init_bonus.c \
	bonus/srcs/init/init_info_bonus.c \
	bonus/srcs/free/free_bonus.c \
	bonus/srcs/run/run_program_bonus.c \
	bonus/srcs/run/pipe_utils_bonus.c \
	bonus/srcs/run/heredoc_bonus.c \
	bonus/srcs/validation/invalid.c \
	bonus/gnl/get_next_line_bonus.c \
	bonus/gnl/get_next_line_utils_bonus.c

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

.c.o :
	$(CC) $(FLAG) -c $< -o $(<:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(RM) $(BONUS_OBJS)
	make -C $(LIB)
	mv $(LIB)/libft.a libft.a
	$(CC) $(FLAG) $(OBJS) libft.a -o $(NAME)

bonus : $(BONUS_OBJS)
	$(RM) $(OBJS)
	make -C $(LIB)
	cp $(LIB)/libft.a libft.a
	$(CC) $(FLAG) $(BONUS_OBJS) libft.a -o $(NAME)

clean :
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean : clean
	make fclean -C $(LIB)
	$(RM) $(NAME) libft.a

re : fclean all