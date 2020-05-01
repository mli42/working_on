# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mli <mli@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/01 19:31:11 by mli               #+#    #+#              #
#    Updated: 2020/05/01 23:42:29 by mli              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btree.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

ifeq ($(cc), db)
 CFLAGS +=  -fsanitize=address -g3
endif

SRCS = btree_create_node.c \
	   btree_apply_infix.c btree_apply_prefix.c btree_apply_suffix.c \
	   btree_insert_data.c

OBJS_PATH = ./obj/
OBJS = ${addprefix ${OBJS_PATH}, ${SRCS:.c=.o}}

$(NAME): ${OBJS_PATH} ${OBJS}
	ar rcs ${NAME} ${OBJS}

all: ${NAME}

${OBJS_PATH}:
	@mkdir -p ${OBJS_PATH}

${OBJS_PATH}%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -rf ${OBJS_PATH}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
