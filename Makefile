# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdeville <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/08 15:53:42 by mdeville          #+#    #+#              #
#    Updated: 2017/07/08 22:26:17 by mdeville         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC= gcc
CCFLAGS= -Wall -Wextra -Werror


all: sastantua

%.o : &.c
	$(CC) $(CCFLAGS) -c -o $@ $^

sastantua : ft_putchar.c sastantua.c main.c ft_atoi.c
	$(CC) $(CCFLAGS) -o $@ $^

clean:
	find . \( -name "*.o" -o -perm +100 \) -print -delete
