# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niboukha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/08 15:19:38 by niboukha          #+#    #+#              #
#    Updated: 2023/09/08 15:27:39 by niboukha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC =

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)


clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all re clean fclean
