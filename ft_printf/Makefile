# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rliu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/21 20:09:37 by rliu              #+#    #+#              #
#    Updated: 2022/02/23 11:33:58 by rliu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= srcs/pt_pxX.c srcs/pt_csdiu.c srcs/ft_printf.c

OBJS 	= ${SRCS:.c=.o}

NAME	= libftprintf.a

CC		= gcc

AR		= ar rcs

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:		${CC} ${CFLAGS} -c $< -o ${<: .c=.o}

${NAME}:	${OBJS} 
			${AR} ${NAME} ${OBJS}

all:		${NAME}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:     all fclean clean re
