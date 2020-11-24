# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/24 15:19:33 by romanbtt          #+#    #+#              #
#    Updated: 2020/11/24 16:05:14 by romanbtt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror
INC_DIR = includes
SRC_DIR = sources

NAME = libgetnextline.a

SRC_FILES =	get_next_line.c \
			get_next_line_utils.c

SRCS = $(addprefix $(SRC_DIR)/,$(SRC_FILES))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(NAME) created"

%.o: %.c
	@gcc $(FLAG) -I $(INC_DIR) -c $< -o $@
	@echo "$@ created from $<"

clean:
	@rm -f $(OBJS)
	@echo "OBJECTS deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all
