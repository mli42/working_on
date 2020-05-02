# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mli <mli@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/01 19:31:11 by mli               #+#    #+#              #
#    Updated: 2020/05/02 14:26:48 by mli              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btree.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

ifeq ($(cc), db)
 CFLAGS +=  -fsanitize=address -g3
endif

SRCS = btree_new.c \
	   btree_apply_infix.c btree_apply_prefix.c btree_apply_suffix.c \
	   btree_add.c btree_find.c

OBJS_PATH = ./obj/
OBJS = ${addprefix ${OBJS_PATH}, ${SRCS:.c=.o}}

all:
	@echo "\033[0;1mMake \033[94m${CFLAGS} \033[92m${NAME}\033[0m :"
	@make ${NAME}

$(NAME): ${OBJS_PATH} ${OBJS}
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
