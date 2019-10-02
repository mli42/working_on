# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mli <mli@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/28 16:14:12 by mli               #+#    #+#              #
#    Updated: 2019/10/02 22:27:26 by mli              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= bsq

CC			= gcc
FLAGS		= -Wall -Werror -Wextra

INCL_PATH	= ./includes/
INCL_FILE	= ft_includes.h
INCLUDE		= ${addprefix ${INCL_PATH}, ${INCL_FILE}}

FILES		= main.c \
			  ft_length.c \
			  ft_map.c \
			  ft_bsq.c

.c.o:
	${CC} ${FLAGS} -c $< -I ${INCL_PATH}

${NAME}: ${FILES:.c=.o}
	${CC} ${FLAGS} -o ${NAME} ${FILES:.c=.o}

all: ${NAME}

clean:
	rm -f ${FILES:.c=.o}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: re all clean fclean
