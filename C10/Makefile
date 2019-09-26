# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mli <mli@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 19:56:03 by mli               #+#    #+#              #
#    Updated: 2019/09/26 23:47:51 by mli              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

INCLUDE_PATH = /includes

FILES = ft_display_file.c

CC = gcc

FLAGS = -Wall -Werror -Wextra

OBJ	= ${FILES:.c=.o}

RM = rm -f

.c.o:
	${CC} ${FLAGS} -c ${FILES} -I ${INCLUDE_PATH}

${NAME}: ${OBJ}
	${CC} ${FLAGS} -o ${NAME} ${OBJ} -I ${INCLUDE_PATH}

all: ${NAME}

clean:
	${RM} ${FILES:.c=.o}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: re all clean fclean
