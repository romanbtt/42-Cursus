/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:18:44 by romanbtt          #+#    #+#             */
/*   Updated: 2020/12/02 08:41:54 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** print_space_left() is used to print padding before the output decimal.
** If x->precision value is 0 and x->zero is not active,
** then we print padding of the difference of x->width and length.
** If x->precision is different than 0 and x->zero is not active :
**     If x->precision is less than length, we print padding of the
**     difference of x->width and length.
**     If nb is positive, we print padding of the difference of x->width
**     and x->precision.
**     Else, we print a padding of the difference of x->width and
**     x->precision + 1.
*/

static void			print_space_left(t_flags *x, int length, int nb)
{
	if (!x->precision && !x->zero)
		padding(x->width, length, false, x);
	if (x->precision && !x->zero)
	{
		if (x->precision < length)
			padding(x->width, length, false, x);
		else if (nb >= 0)
			padding(x->width, x->precision, false, x);
		else
			padding(x->width, x->precision + 1, false, x);
	}
}

/*
** print_zero_left() is used to print padding of zeros and to print the
** minus sign and convert the decimal int into an unsigned int.
** If x->zero is active is active :
**     If nb is positive, then we set x->precision to x->width.
**     Else, we set x->precision to x->width -1;
** If nb is negative, we print the minus sign '-' and we inverse the decimal
** into a positive one.
** Then we print padding of zeros of the difference of x->precision and
** length - 1.
** Else, we print padding of zeros of the difference of x->precision and length
** Finally, we store the decimal into the unsigned int 'nb_u'.
*/

static unsigned int	print_zero_left(t_flags *x, int length, int nb)
{
	unsigned int nb_u;

	if (x->zero)
	{
		if (nb >= 0)
			x->precision = x->width;
		else
			x->precision = x->width - 1;
	}
	if (nb < 0)
	{
		output("-", 1, x);
		nb = nb * -1;
		padding(x->precision, length - 1, true, x);
	}
	else
		padding(x->precision, length, true, x);
	nb_u = nb;
	return (nb_u);
}

/*
** print_space_right() is used to print padding of spaces after the decimal
** output.
** If length is greater than x->precision, then we call padding() to print
** padding of spaces of the difference of x->width and length.
** Else, if nb is nagative, we call padding() to print padding of spaces of the
** difference of x->width and x->precision + 1.
** Else, we call padding() to print padding of spaces of the difference of
** x->width and x->precision.
*/

static void			print_space_right(t_flags *x, int length, int nb)
{
	if (length > x->precision)
		padding(x->width, length, false, x);
	else
	{
		if (nb < 0)
			padding(x->width, x->precision + 1, false, x);
		else
			padding(x->width, x->precision, false, x);
	}
}

/*
** First, we declare an int 'nb' to store the decimal, an int 'length' to store
** the length of the decimal,
** and an unsigned int 'nb_u' to store the unsigned form of the decimal.
** We call ftintlen() to get the length nb.
** If x->dot is active and both of x->precision and nb are equal to 0, then we
** print padding of spaces of the size of x->width.
** Else, if x->minus is not active, we call print_space_left().
** Then we call print_zero_left() who handles to print padding of zero and the
** minus sign. This function returns the unsigned version of 'nb'
** store at nb_u.
** If nb_u is equal to 2147483648, then we print this number.
** Else, we comvert the number into a string with ft_itoa(), and we print
** the string.
** If x->minus is active, we call print_space_right().
** Finally, we freed the pointer 'str'.
*/

void				format_int(t_flags *x)
{
	int				nb;
	int				length;
	unsigned int	nb_u;
	char			*str;

	nb = va_arg(x->args, int);
	length = (int)ft_intlen(nb, 10);
	if (x->dot && !x->precision && !nb)
		padding(x->width, 0, false, x);
	else
	{
		if (!x->minus)
			print_space_left(x, length, nb);
		nb_u = print_zero_left(x, length, nb);
		if (nb_u == 2147483648)
			output("2147483648", 10, x);
		else
		{
			str = ft_itoa(nb_u);
			output(str, length, x);
			free(str);
		}
		if (x->minus)
			print_space_right(x, length, nb);
	}
}
