# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 13:56:55 by jbartosi          #+#    #+#              #
#    Updated: 2023/02/15 16:02:45 by jbartosi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
PRINTF = ft_printf
LIBFT = ft_printf/libft

SRC = push_swap.c list_manipul.c checker.c actions.c combine_actions.c
OBJ = $(SRC:.c=.o)

all: lib $(NAME)

lib:
	@make -C $(PRINTF)
	@echo "Finished making libraries :D"

$(NAME): $(OBJ)
	cc $(CFLAGS) -L $(LIBFT) -L $(PRINTF) -o $@ $^ -lft -lftprintf

clean:
	@make clean -C $(PRINTF)
	@rm -f $(OBJ)

fclean:
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@make fclean -C $(PRINTF)

re:	fclean
	@make all

.PHONY: re, fclean, clean
