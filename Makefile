# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 16:30:26 by rdias-ba          #+#    #+#              #
#    Updated: 2023/05/15 17:39:01 by rdias-ba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
BONUS_NAME	= checker
LIB_NAME	= libft
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

SRCS_DIR	= srcs/
SRCS_DIR_BONUS = srcs_bonus/
OBJS_DIR	= objs/
OBJS_DIR_BONUS = objs_bonus/
LIB_DIR		= libft/
INCLUDE		= include/
INCLUDE_BONUS = include_bonus/

SRCS		= main.c tab_struct.c push_utils.c tab_struct_utils.c params_checking.c swap_utils.c \
 				rotate_utils.c reverse_rotate_utils.c sorting_utils.c string_low_args.c sorting_big.c \
				error.c parsing.c params_checking_one_arg.c\
				
SRCS_BONUS	= main.c error_bonus.c params_checking_bonus.c params_checking_one_arg_bonus.c parsing_bonus.c tab_struct_bonus.c tab_struct_utils_bonus.c\
				read_from_stdin_bonus.c push_utils_bonus.c swap_utils_bonus.c rotate_utils_bonus.c reverse_rotate_utils_bonus.c check_is_sorted_bonus.c\

OBJS		= $(SRCS:%.c=$(OBJS_DIR)%.o)

OBJS_BONUS	= $(SRCS_BONUS:%.c=$(OBJS_DIR_BONUS)%.o)

all: $(NAME) bonus

$(NAME): $(OBJS_DIR) $(OBJS) $(LIB_DIR)$(LIB_NAME).a
			$(CC) $(CFLAGS) $(OBJS) $(LIB_DIR)$(LIB_NAME).a -o $@

$(OBJS_DIR):
			mkdir -p $@

$(OBJS): $(OBJS_DIR)%.o: $(SRCS_DIR)%.c
			$(CC) $(CFLAGS) -I$(INCLUDE) -I$(LIB_DIR)include -g -c $< -o $@

$(LIB_DIR)$(LIB_NAME).a:
			$(MAKE) -C $(LIB_DIR)
bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJS_DIR_BONUS) $(OBJS_BONUS) $(LIB_DIR)$(LIB_NAME).a
			$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIB_DIR)$(LIB_NAME).a -o $@

$(OBJS_DIR_BONUS):
			mkdir -p $@

$(OBJS_BONUS): $(OBJS_DIR_BONUS)%.o: $(SRCS_DIR_BONUS)%.c
			$(CC) $(CFLAGS) -I$(INCLUDE_BONUS) -I$(LIB_DIR)include -g -c $< -o $@

clean:
	rm -rf $(OBJS_DIR) $(OBJS_DIR_BONUS)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -rf $(NAME) $(BONUS_NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re