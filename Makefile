# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdias-ba <rdias-ba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 16:30:26 by rdias-ba          #+#    #+#              #
#    Updated: 2023/03/15 17:55:29 by rdias-ba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
LIB_NAME	= libft
CC			= gcc
CFLAGS		= #-Wall -Werror -Wextra

SRCS_DIR	= srcs/
OBJS_DIR	= objs/
LIB_DIR		= libft/
INCLUDE		= include/

SRCS		= main.c tab_struct.c push_utils.c tab_struct_utils.c params_checking.c swap_utils.c \
 				rotate_utils.c reverse_rotate_utils.c sorting_utils.c string_low_args.c sorting_big.c \

OBJS		= $(SRCS:%.c=$(OBJS_DIR)%.o)

all: $(OBJS_DIR) $(NAME)

$(NAME): $(OBJS) $(LIB_DIR)$(LIB_NAME).a
			$(CC) $(CFLAGS) $^ -o $@

$(OBJS_DIR):
			mkdir -p $@

$(OBJS): $(OBJS_DIR)%.o: $(SRCS_DIR)%.c
			$(CC) $(CFLAGS) -I$(INCLUDE) -I$(LIB_DIR)include -g -c $< -o $@

$(LIB_DIR)$(LIB_NAME).a:
			$(MAKE) -C $(LIB_DIR)

clean:
	rm -rf $(OBJS_DIR)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re