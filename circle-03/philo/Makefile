# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: taewan <taewan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/08 23:02:49 by taewan            #+#    #+#              #
#    Updated: 2022/03/15 14:39:55 by taewan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc

HEAD = -I includes

FLAG = -Wall -Wextra -Werror $(HEAD) -g3

SRCS = srcs/main.c \
	srcs/setting.c \
	srcs/utils.c \
	srcs/running.c

OBJS = $(SRCS:.c=.o)

.c.o :
	$(CC) $(FLAG) -c $< -o $(<:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAG) $(OBJS) -o $(NAME)

clean :
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all