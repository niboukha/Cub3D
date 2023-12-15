CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3

NAME = cub3D
NAME_BONUS = cub3D_bonus
LIBFT = ./lib/libft/libft.a

MLX = -lmlx -framework OpenGL -framework AppKit

LIB = $(LIBFT)
SRC = $(wildcard ./src/*.c ./src/**/*.c)
OBJ = $(SRC:.c=.o)

all : $(NAME) #$(NAME_BONUS)

bonus : $(NAME_BONUS)

$(LIBFT) : $(wildcard ./lib/libft/*.c)
	@echo "⌛ Compiling libft\n"
	@make -C ./lib/libft
	@make -C ./lib/libft bonus
	@make -C ./lib/libft clean

$(NAME): $(SRC) $(LIB)
	@echo "$(GREEN)⌛ Compiling $(NAME) ...$(END)"
	@$(CC) $(CFLAGS) $(SRC) $(LIB) $(MLX) -o $(NAME)
	@echo "✅ $(NAME) compiled successfully\n"

$(NAME_BONUS) : $(SRC) $(LIB)
	@echo "$(GREEN)⌛ Compiling $(NAME_BONUS) ...$(END)"
	@$(CC) $(CFLAGS) $(SRC) $(LIB) $(MLX) -o $(NAME_BONUS)
	@echo "✅ $(NAME_BONUS) compiled successfully\n"

%.o : %.c cub3d.h
	$(CC) $(CFLAGS) $< -c -o $@

clean :
	@rm -rf $(OBJ)
	@make -C  ./lib/libft clean
	@echo "🗑️  objects removed \n"

fclean : clean
	@rm -rf $(NAME) $(NAME_BONUS)
	@make -C  ./lib/libft fclean
	@echo "🗑️  $(NAME) $(OBJ) removed \n"

re : fclean all

.PHONY: all clean fclean re
