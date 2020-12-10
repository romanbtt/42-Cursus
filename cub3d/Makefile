NAME =		cub3D

FLAGS_WWW = -Wall -Wextra -Werror
LIBS_MLX_FT = -L ./$(LIBFT_DIR) -lft -L ./$(MLX_DIR) -lmlx
FLAGS_LIBS = -lm -lbsd -lX11 -lXext $(LIBS_MLX_FT)

SRC_DIR = 	sources
MLX_DIR =	mlx_linux
LIBFT_DIR = libft

INCLUDES = -I./includes -I./$(MLX_DIR) -I./$(LIBFT_DIR)/includes

SRC_FILES =	main.c 

SRCS = $(addprefix $(SRC_DIR)/,$(SRC_FILES))

OBJS = 	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(MLX_DIR)
	@make -C $(LIBFT_DIR)
	@clang $(OBJS) $(INCLUDES) $(FLAGS_WWW) $(FLAGS_LIBS) -o $(NAME)

%.o: %.c
	@clang -Wall -Wextra -Werror $(INCLUDES) -c $< -o $@
	@echo "$@ created from $<"

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	@echo "OBJECTS deleted"

fclean: clean
	@rm -f $(NAME)
	@rm -f *.bmp
	@make fclean -C $(LIBFT_DIR)
	@echo "$(NAME) deleted"

re: fclean all
