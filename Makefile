# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaille <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/25 00:22:44 by abaille           #+#    #+#              #
#    Updated: 2018/01/25 00:22:46 by abaille          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft
SRCS = fillit.c ft_algo.c ft_check.c ft_list.c \
       ft_lstadend.c ft_map.c ft_wmap.c
OBJS = ${SRCS:.c=.o}

all: $(NAME)
%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@
$(NAME): $(OBJS)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(LIBFT) -lft
clean:
	make -C $(LIBFT) clean
	rm -f $(OBJS)
fclean: clean
	make -C $(LIBFT) fclean
	rm -f $(NAME)
re: fclean all

.PHONY: clean fclean