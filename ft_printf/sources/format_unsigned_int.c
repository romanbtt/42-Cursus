/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_unsigned_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:15:55 by romanbtt          #+#    #+#             */
/*   Updated: 2020/11/30 22:06:04 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** The print_space_right() is used to print padding of spaces after the
** unsigned int.
** If x->precision == 0 and x->zero is not active, then we call padding()
** to print the difference of x->width and length with spaces.
** If x->precision is diiferent than 0 and x-> is not axtive :
** And if x->precision is less than length, we print the difference of x->width
** and length with spaces.
** else we print the difference between x->width and x->precision.
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
** The print_space_right() is used to print padding of zero before the
** unsigned int.
** If x->zero flag is active, then x->precision = x->width.
** Then we call the padding() function to print the difference of x->precision
** and length with zeros.
*/

static void	print_zero_left(t_flags *x, int length)
{
	if (x->zero)
		x->precision = x->width;
	padding(x->precision, length, true, x);
}

/*
** The print_space_right() is used to print padding of space before the
** unsigned int.
** If the length of the number is greater than x->precision we print
** the difference between x->width and length with spaces.
** Else, we print the difference between x->width and x->precision with spaces.
*/

static void	print_space_right(t_flags *x, int length)
{
	if (length > x->precision)
		padding(x->width, length, false, x);
	else
		padding(x->width, x->precision, false, x);
}

/*
** We first declare an unsigned int "nb" variable to store the unsigned int
** decimal and an int "length" to store the length of the decimal which the
** use of ft_uintlen() function.
** If x->dot is active but with no x->precision and nb == 0, then we print a
** padding of space with the size x->width.
** Else we check if x->minus is not active, if it is the case, we call
** print_space_left() to print the padding of space before the number.
** Then we call print_zero_left() to print the padding of zero before the
** number and output() with the parameter of ullitoa_base(nb, 10) to convert
** the decimal in string.
** If x->minus is active, then we call print_space_right() to print the padding
** after the number.
*/

void		format_unsigned_int(t_flags *x)
{
	unsigned int	nb;
	int				length;
	char			*str;

	nb = va_arg(x->args, unsigned int);
	length = (int)ft_uintlen(nb, 10);
	str = ft_ullitoa_base(nb, 10);
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
