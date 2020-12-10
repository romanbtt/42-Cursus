/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 21:33:42 by romanbtt          #+#    #+#             */
/*   Updated: 2020/11/30 22:18:48 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** print_space_left() is used to print padding before the output decimal.
** If x->precision and x->zero are not active, we print padding of the
** difference of x->width and length.
** If x->precision value is different than 0 and x->zero is not active :
** 	If x->precision is less than length, we print padding of the
**     difference of x->width and length.
**     Else, we print a padding of the difference of x->width and
**     x->precision.
*/

static void	print_space_left(t_flags *x, int length)
{
	if (!x->precision && !x->zero)
		padding(x->width, length, false, x);
	if (x->precision && !x->zero)
	{
		if (x->precision < length)
			padding(x->width, length, false, x);
		else
			padding(x->width, x->precision, false, x);
	}
}

/*
** print_zero_left() is used to print padding of zeros before the format_low_hex
** output.
** If x->zero is active, then we set x->precision to x->width.
** Then we print padding of zeros of the difference of x->precision and length.
*/

static void	print_zero_left(t_flags *x, int length)
{
	if (x->zero)
		x->precision = x->width;
	padding(x->precision, length, true, x);
}

/*
** print_space_right() is used to print padding of spaces after the hex
** output.
** If length is greater than x->precision, then we call padding() to print
** padding of spaces of the difference of x->width and length.
** Else, we call padding() to print padding of spaces of the difference of
** x->width and x->precision.
*/

static void	print_space_right(t_flags *x, int length)
{
	if (length > x->precision)
		padding(x->width, length, false, x);
	else
		padding(x->width, x->precision, false, x);
}

/*
** First, we declare an int 'i' as an index to transform each char of
** str to lower case. An unsigned int 'nb' is used to store the decimal value.
** An int 'length' is used to store the length of the decimal 'nb'.
** A char * 'str' is used to store the hexadecimal format of 'nb' with the
** help of ullitoa_base() with a 16 base as parameter.
** The while loop is used to transform the str in lowercase since
** ullitoa_base() return uppercase char.
** If x->dot is active and both of x->precision and nb are equal to 0, then we
** print padding of spaces of the size of x->width.
** Else, if x->minus is not active, we call print_space_left().
** Then we call print_zero_left() who handles to print padding of zero and the
** minus sign. This function returns the unsigned version of 'nb'
** store at nb_u.
** The string format of 'nb_u' is store inside str with the help of
** ullitoa_base().
** Then we call output() to print str.
** If x->minus is active, we call print_space_right().
** Finally, we freed the pointer 'str'.
*/

void		format_low_hex(t_flags *x)
{
	int				i;
	unsigned int	nb;
	int				length;
	char			*str;

	i = 0;
	nb = va_arg(x->args, unsigned int);
	length = (int)ft_uintlen(nb, 16);
	str = ft_ullitoa_base(nb, 16);
	while ((str[i] = ft_tolower(str[i])))
		i++;
	if (x->dot && !x->precision && !nb)
		padding(x->width, 0, false, x);
	else
	{
		if (!x->minus)
			print_space_left(x, length);
		print_zero_left(x, length);
		output(str, length, x);
		if (x->minus)
			print_space_right(x, length);
	}
	free(str);
}

/*
** An unsigned int 'nb' is used to store the decimal value.
** An int 'length' is used to store the length of the decimal 'nb'.
** A char * 'str' is used to store the hexadecimal format of 'nb' with the
** help of ullitoa_base() with a 16 base as parameter.
** If x->dot is active and both of x->precision and nb are equal to 0, then we
** print padding of spaces of the size of x->width.
** Else, if x->minus is not active, we call print_space_left().
** Then we call print_zero_left() who handles to print padding of zero and the
** minus sign. This function returns the unsigned version of 'nb'
** store at nb_u.
** The string format of 'nb_u' is store inside str with the help of
** ullitoa_base().
** Then we call output() to print str.
** If x->minus is active, we call print_space_right().
** Finally, we freed the pointer 'str'.
*/

void		format_up_hex(t_flags *x)
{
	unsigned int	nb;
	int				length;
	char			*str;

	nb = va_arg(x->args, unsigned int);
	length = (int)ft_uintlen(nb, 16);
	str = ft_ullitoa_base(nb, 16);
	if (x->dot && x->precision == 0 && nb == 0)
		padding(x->width, 0, false, x);
	else
	{
		if (!x->minus)
			print_space_left(x, length);
		print_zero_left(x, length);
		output(str, length, x);
		if (x->minus)
			print_space_right(x, length);
	}
	free(str);
}
