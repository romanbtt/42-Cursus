# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 21:34:55 by romanbtt          #+#    #+#              #
#    Updated: 2020/11/27 09:42:34 by romanbtt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror
INC_DIR = includes
INC_LIBFT_DIR = libft/includes
SRC_DIR = sources
LIBFT_DIR = libft

NAME = libftprintf.a
LIBFT = $(LIBFT_DIR)/libft.a

SRC_FILES =	ft_printf.c \
			ft_printf_utils.c \
			flags.c \
			format_char.c \
			format_string.c \
			format_pointer.c \
			format_int.c \
			format_unsigned_int.c \
			format_percent.c \
			format_hex.c

SRCS = $(addprefix $(SRC_DIR)/,$(SRC_FILES))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@cp $(LIBFT) ./$(NAME)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(NAME) created"

%.o: %.c
	@gcc $(FLAG) -I $(INC_DIR) -I $(INC_LIBFT_DIR) -c $< -o $@
	@echo "$@ created from $<"

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT_DIR)
	@echo "OBJECTS deleted"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "$(NAME) deleted"

re: fclean all
