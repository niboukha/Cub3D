CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

NAME = cub3D
LIBFT = ./lib/libft/libft.a

# Source files
MLXL = -L./minilibx-linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

LIB = $(LIBFT)
SRC = $(wildcard ./src/*.c ./src/**/*.c)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT): $(wildcard ./lib/libft/*.c)
	@echo "⌛ Compiling libft\n"
	@make -C ./lib/libft
	@make -C ./lib/libft bonus
	@make -C ./lib/libft clean

$(MLXL): $(wildcard ./minilibx-linux/*.c)
	@echo "⌛ Compiling minilibx\n"
	@make -C ./minilibx-linux

$(NAME): $(SRC) $(LIB) $(MLXL)
	@echo "$(GREEN)⌛ Compiling $(NAME) ...$(END)"
	@$(CC) $(CFLAGS) $(SRC) $(LIB) $(MLXL) -o $(NAME)
	@echo "✅ $(NAME) compiled successfully\n"

%.o : %.c cub3d.h
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	@rm -rf $(OBJ)
	@make -C ./lib/libft clean
	@echo "🗑️  objects removed \n"

fclean: clean
	@rm -rf $(NAME)
	@make -C ./lib/libft fclean
	@echo "🗑️  $(NAME) $(OBJ) removed \n"

re: fclean all

.PHONY: all clean fclean re
