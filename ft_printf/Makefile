NAME = libftprintf.a
CFLAGS =  -I. -c

SRC = flags.c format_char.c format_string.c formats.c ft_printf_utils.c ft_printf.c print.c


OBJ = $(SRC:.c=.o)


all: $(NAME) #$(so)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ): $(SRC)
	gcc $(CFLAGS) -c $(SRC)


#so:
#	gcc -fPIC -Wall -Werror -Wextra -c libft.h $(SRC) $(SRC_BONUS)
#	gcc -shared  -o libft.so $(OBJ) $(OBJ_BONUS)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME) *.gch *.so

re: fclean all