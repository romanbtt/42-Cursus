NAME = libftprintf.a
CFLAGS =  -I. -c

SRC = flags.c format_char.c format_string.c format_pointer.c \
	format_int.c format_unsigned_int.c format_percent.c format_hex.c \
	ft_printf_utils.c ft_printf.c print.c 


OBJ = $(SRC:.c=.o)


all: $(NAME) #$(so)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ): $(SRC)
	gcc $(CFLAGS) -c $(SRC)


clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME) *.gch *.so

re: fclean all