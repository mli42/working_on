# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mli <mli@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/01 19:31:11 by mli               #+#    #+#              #
#    Updated: 2020/05/01 20:36:16 by mli              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btree.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

ifeq ($(cc), db)
 CFLAGS +=  -fsanitize=address -g3
endif

SRCS = btree_create_node.c \
	   btree_apply_infix.c btree_apply_prefix.c btree_apply_suffix.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

$(NAME): ${OBJS} 
	ar rcs ${NAME} ${OBJS}


.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
