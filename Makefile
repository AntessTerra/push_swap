# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 13:56:55 by jbartosi          #+#    #+#              #
#    Updated: 2023/02/28 09:12:39 by jbartosi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
CFLAGS = -Wall -Wextra -Werror
PRINTF = ft_printf
LIBFT = ft_printf/libft

SRC = push_swap.c list_manipul.c checker_utils.c actions.c combine_actions.c bubble_sort.c utils.c utils2.c radix_sort.c small_sort.c fastest_sort.c
OBJ = $(SRC:.c=.o)

SRC_BONUS = checker.c list_manipul.c checker_utils.c actions.c combine_actions.c bubble_sort.c utils.c utils2.c radix_sort.c small_sort.c fastest_sort.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: lib $(NAME)

bonus: lib $(NAME_BONUS)

lib:
	@make -C $(PRINTF)
	@echo "Finished making libraries :D"

$(NAME_BONUS): $(OBJ_BONUS)
	@cc $(CFLAGS) -L $(LIBFT) -L $(PRINTF) -o $@ $^ -lft -lftprintf
	@echo "Finished making CHECKER :D"

$(NAME): $(OBJ)
	@cc $(CFLAGS) -L $(LIBFT) -L $(PRINTF) -o $@ $^ -lft -lftprintf
	@echo "Finished making PUSH_SWAP :D"

clean:
	@make clean -C $(PRINTF)
	@rm -f $(OBJ)
	@rm -f $(OBJ_BONUS)
	@echo "Finished cleaning :D"

fclean:
	@rm -f $(OBJ)
	@rm -f $(OBJ_BONUS)
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@make fclean -C $(PRINTF)
	@echo "Finished force cleaning :D"

re:	fclean
	@make all

.PHONY: re, fclean, clean
