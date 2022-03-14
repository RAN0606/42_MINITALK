# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rliu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 17:01:08 by rliu              #+#    #+#              #
#    Updated: 2022/03/02 17:27:42 by rliu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CLIENT	= 	client

SERVER	=	server

SRCS_C	=	src/client.c

SRCS_S	=	src/server.c

SRCS_BC	=	bonus/client_bonus.c

SRCS_BS	=	bonus/server_bonus.c

OBJS_C 	=	$(SRCS_C:.c=.o)

OBJS_S	=	$(SRCS_S:.c=.o)

OBJS_BC =	$(SRCS_BC:.c=.o)

OBJS_BS	=	$(SRCS_BS:.c=.o)

CFLAGS	= 	-Wall -Wextra -Werror

IFLAGS	=	-I. -I./libft -I. -I./ft_printf/srcs

LFLAGS	=	-L./libft -lft -L./ft_printf -lftprintf

%.o:		%.c
			clang $(CFLAGS) $(IFLAGS) -c $< -o $@

all:		$(CLIENT) $(SERVER)

$(CLIENT):	$(OBJS_C)
			$(MAKE) -C libft
			$(MAKE) -C ft_printf
			gcc $(CFLAGS) $(OBJS_C) $(LFLAGS) $(IFLAGS) -o $(CLIENT)


$(SERVER):	$(OBJS_S)
			$(MAKE) -C libft
			$(MAKE) -C ft_printf
			gcc $(CFLAGS) $(OBJS_S) $(LFLAGS) $(IFLAGS) -o $(SERVER)

bonus: 		$(OBJS_BC) $(OBJS_BS)
			$(MAKE) -C libft
			$(MAKE) -C ft_printf
			gcc $(CFLAGS) $(OBJS_BC) $(LFLAGS) $(IFLAGS) -o client_bonus
			gcc $(CFLAGS) $(OBJS_BS) $(LFLAGS) $(IFLAGS) -o server_bonus

clean:
			$(MAKE) -C libft clean
			$(MAKE) -C ft_printf clean
			rm -f $(OBJS_C)
			rm -f $(OBJS_S)
			rm -f $(OBJS_BC)
			rm -f $(OBJS_BS)

fclean:		clean
			$(MAKE) -C libft fclean
			$(MAKE) -C ft_printf fclean
			rm -f $(CLIENT)
			rm -f $(SERVER)
			rm -f client_bonus
			rm -f server_bonus

re:			fclean all

.PHONY:     all fclean clean re bonus
