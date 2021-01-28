NAME =		cub3D

FLAGS_WWW = -Wall -Wextra -Werror
LIBS_MLX_FT = -L ./$(LIBFT_DIR) -lft -L ./$(MLX_DIR) -lmlx
FLAGS_LIBS = -lm -lbsd -lX11 -lXext $(LIBS_MLX_FT)

SRC_DIR = 	sources
MLX_DIR =	mlx_linux
LIBFT_DIR = libft

INCLUDES = -I./includes -I./$(MLX_DIR) -I./$(LIBFT_DIR)/includes

SRC_FILES =	main.c \
			process_map_file.c \
			get_textures.c \
			get_next_line.c \
			get_map_identifier_1.c \
			get_map_identifier_2.c \
			cub_utils.c \
			get_line_map.c \
			is_map_valid.c \
			move_player.c \
			update_game.c  \
			key_events.c \
			get_info_player.c \
			get_info_sprites.c \
			raycasting.c \
			raycasting_horz.c \
			render_projection_1.c \
			render_projection_2.c \
			exit_game.c \
			raycasting_vert.c \
			render_sprites.c \
			save_bmp.c

SRCS = $(addprefix $(SRC_DIR)/,$(SRC_FILES))

OBJS = 	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(MLX_DIR)
	@make -C $(LIBFT_DIR)
	@clang $(OBJS) $(INCLUDES) $(FLAGS_WWW) $(FLAGS_LIBS) -o $(NAME)

%.o: %.c
	# -w -g to remove !!!!!!!!!
	@clang -g $(FLAGS_WWW) $(INCLUDES) -c $< -o $@
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
