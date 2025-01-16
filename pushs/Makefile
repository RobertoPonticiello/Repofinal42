# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyriarte <jyriarte@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 23:57:50 by jyriarte          #+#    #+#              #
#    Updated: 2025/01/16 00:03:42 by jyriarte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker

LIBFT_PATH=libft
LIBFT=$(LIBFT_PATH)/libft.a
LIBFT_FLAG= -L$(LIBFT_PATH) -lft

CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -I$(LIBFT_PATH)

SOURCES = mandatory/push_swap.c mandatory/utils.c mandatory/parse_args.c \
		  mandatory/stack_utils.c mandatory/sort_stack.c mandatory/sort_utils.c \
		  mandatory/stack_operations.c mandatory/both_operations.c

BONUS_SOURCES = bonus/checker_bonus.c bonus/utils_bonus.c \
				bonus/read_input_bonus.c bonus/parse_args_bonus.c \
				bonus/stack_utils_bonus.c bonus/stack_operations_bonus.c

OBJECTS = $(SOURCES:.c=.o)
BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

$(NAME): $(LIBFT) $(OBJECTS)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_FLAG)
	@echo "$(NAME) OK!"

$(BONUS): $(LIBFT) $(BONUS_OBJECTS)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_FLAG)
	@echo "$(BONUS) OK!"

$(LIBFT):
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@  

bonus: $(BONUS)

all: $(NAME) $(BONUS)

clean:
	@$(RM) $(OBJECTS) 
	@$(RM) $(BONUS_OBJECTS) 
	@$(MAKE) --no-print-directory -C $(LIBFT_PATH) clean

fclean: clean
	@$(RM) $(NAME) 
	@$(RM) $(BONUS) 
	@$(RM) $(LIBFT)

re: fclean all

.PHONY: all re clean fclean bonus
