# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpontici <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 12:59:10 by rpontici          #+#    #+#              #
#    Updated: 2024/12/09 20:22:01 by rpontici         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra

all: final

final: main.o
	gcc $(CFLAGS) main.o
	chmod +x final

main.o: main.c
	gcc $(CFLAGS) -c main.c

clan:
	echo "removing everyting but the source files"
	rm main.o

