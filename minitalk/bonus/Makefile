# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 16:43:05 by jaeyyoo           #+#    #+#              #
#    Updated: 2023/05/31 16:00:05 by jaeyyoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

CLIENT_NAME = client
SERVER_NAME = server

SERVER_SRCS = ./server_bonus.c
CLIENT_SRCS = ./client_bonus.c

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all :
	make -C ../libft all
	make client_bonus
	make server_bonus

bonus :
	make client_bonus
	make server_bonus

server_bonus : $(SERVER_NAME)

client_bonus : $(CLIENT_NAME)

$(SERVER_NAME) : $(SERVER_OBJS)
	$(CC) $(CFLAGS) $^ -L ../libft -lft -o $@

$(CLIENT_NAME) : $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $^ -L ../libft -lft -o $@

clean :
	@make -C ../libft clean
	@rm -f $(SERVER_OBJS) $(CLIENT_OBJS)

fclean :
	@make -C ../libft fclean
	@make clean
	@rm -f $(SERVER_NAME) $(CLIENT_NAME)

re :
	make fclean
	make all

.PHONY: all clean fclean re bonus client_bonus server_bonus
