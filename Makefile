# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guroux <guroux@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/10 11:58:48 by guroux            #+#    #+#              #
#    Updated: 2019/09/10 12:20:15 by guroux           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all libft clean fclean re

include mk/files.mk

NAME = ft_select

OBJECT = $(SRC:.c=.o)

LIB = libft

CC = gcc

FLAGS = -Wall -Wextra -Werror

GREEN = \033[0;32m
WHITE = \033[1;37m
BLUE = \033[1;34m
RED = \033[0;31m
YELLOW = \033[1;33m

OKGREEN = $(YELLOW) $(GREEN)[OK]$(WHITE)
KORED = $(YELLOW) $(RED)[error]$(WHITE)


$(NAME): $(LIB) $(OBJECT)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJECT) -L libft/ -lft && echo "$(BLUE)Compilation$(OKGREEN)" || (echo "$(BLUE)Compilation$(KORED)" && false)

$(LIB):
	@$(MAKE) -C $(LIB)

all: $(NAME)

%.o: %.c
		@$(CC) $(FLAGS) -I $(HEADERS) -I libft/includes $< -c -o $@ && echo "$(BLUE)Objects$(OKGREEN)" || (echo "$(BLUE)Objects$(KORED)" && false)

clean:
	@rm -rf $(OBJECT)
	@echo "$(YELLOW)Deleted objects$(OKGREEN)"
	@$(MAKE) clean -C $(LIB)

fclean: clean
	@rm -rf $(NAME)
	@echo "$(YELLOW)Deleted exe$(OKGREEN)"
	@$(MAKE) fclean -C $(LIB)

re: fclean all
