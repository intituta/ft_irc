# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kferterb <kferterb@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 09:15:49 by kferterb          #+#    #+#              #
#    Updated: 2022/11/04 09:15:50 by kferterb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS =	main.c init_env.c clean_fd.c get_opt.c x.c main_loop.c \
	init_fd.c do_select.c check_fd.c \
	srv_create.c srv_accept.c \
	client_read.c client_write.c

OBJS = ${SRCS:.c=.o}

NAME = bircd

CFLAGS = -I. -g3 -Wall -Werror
LDFLAGS = 

CC = gcc
RM = rm -f

${NAME}:	${OBJS}
		${CC} -o ${NAME} ${OBJS} ${LDFLAGS}

all:		${NAME}

clean:
		${RM} ${OBJS} *~ #*#

fclean:		clean
		${RM} ${NAME}

re:		fclean all
