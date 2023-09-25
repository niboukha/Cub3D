# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niboukha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/08 15:19:38 by niboukha          #+#    #+#              #
#    Updated: 2023/09/25 15:26:26 by niboukha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc

CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3

SRC = cub3d.c map2d.c move_player.c cast_rays.c check_intersection.c\
inter_hor.c inter_ver.c get_dist_wall.c put_pixels.c util_functions.c

MLX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

OBJ = $(SRC:.c=.o)

HEADERS = cub3d.h

all : $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	$(CC) $(CFLAGS) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o : %.c cub3d.h
	$(CC) $(CFLAGS) $< -c -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)
OBJ = $(SRC:.c=.o)
re : fclean all

.PHONY: all re clean fclean
HEADERS = cub3d.h