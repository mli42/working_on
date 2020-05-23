# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mli <mli@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/01 19:31:11 by mli               #+#    #+#              #
#    Updated: 2020/05/23 22:37:58 by mli              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = liblst.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

ifeq ($(cc), db)
 CFLAGS +=  -fsanitize=address -g3
endif

SRCS = 00_ft_create_elem.c 01_ft_list_push_front.c 02_ft_list_size.c \
	   03_ft_list_last.c 04_ft_list_push_back.c 05_ft_list_push_strs.c \
	   06_ft_list_clear.c 07_ft_list_at.c 08_ft_list_reverse.c \
	   09_ft_list_foreach.c 10_ft_list_foreach_if.c 11_ft_list_find.c \
	   12_ft_list_remove_if.c 13_ft_list_merge.c

OBJS_PATH = ./obj/
OBJS = ${addprefix ${OBJS_PATH}, ${SRCS:.c=.o}}

all:
	@echo "\033[0;1mMake \033[94m${CFLAGS} \033[92m${NAME}\033[0m :"
	@make ${NAME}

$(NAME): ${OBJS_PATH} ${OBJS} ft_list.h
	@printf "\n"
	@ar rcs ${NAME} ${OBJS}

${OBJS_PATH}:
	@mkdir -p ${OBJS_PATH}

${OBJS_PATH}%.o: %.c
	@printf "\033[0;7;96m \033[0m"
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@rm -rf ${OBJS_PATH}
	@echo "\033[0;1mDelete \033[91m./objs/\033[0m"

fclean: clean
	@rm -rf ${NAME}
	@echo "\033[0;1mDelete \033[91m${NAME}\033[0m"

re: fclean all

test: re
	${CC} ${CFLAGS} ${NAME} main.c

.PHONY: all clean fclean re
