/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:01:43 by romanbtt          #+#    #+#             */
/*   Updated: 2020/11/30 22:08:55 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** get_precision() is used to get the precision when the x->dot is active.
** If x->precision is greater than the length, or x->precision is negative,
** then we set x->precision at length.
** Else if, x->precision == 0, we set x->precision at 0.
*/

static void	get_precision(t_flags *x, int length)
{
	if ((x->precision > length) || x->precision < 0)
		x->precision = length;
	else if (!x->precision)
		x->precision = 0;
}

/*
** print_space_left() is used to print the padding after the string.
** If x->dot is active, then we print the difference between x->width
** and x->precisation.
** Else, we print the difference between x->width and length.
*/

static void	print_space_left(t_flags *x, int length)
{
	if (x->dot)
		padding(x->width, x->precision, false, x);
	else
		padding(x->width, length, false, x);
}

/*
** print_output() is used to select the length of the output before sending to
** the generic function output()
** If x->dot is active, we call output() with x->precision.
** Else, we call output() with length.
*/

static void	print_output(t_flags *x, int length, char *str)
{
	if (x->dot)
		output(str, x->precision, x);
	else
		output(str, length, x);
}

/*
** print_space_right() is used to print the padding of spaces on the right of
** the output.
** If x->dot is active, we print the difference between x->width and
** x->pecision.
** Else, we print the difference between x->width and length.
*/

static void	print_space_right(t_flags *x, int length)
{
	if (x->dot)
		padding(x->width, x->precision, false, x);
	else
		padding(x->width, length, false, x);
}

/*
** We declare a char * to store the string and an int to store the length
** of the string.
** If str is null, then we have to store the string "(null)" and print it.
** ft_strlen() is called to store the length of str inside length.
** If the flag x->dot is active, then we call get_precision to get the
** precision value.
** If x->minus and x->zero are not active, we call print_space_left() to print
** the padding of spaces before the string.
** If x->zero is active and x->width is greater than length, we call padding(),
** to print the padding of zeros before the string.
** Then we can print the output.
** If x->minus is active, we call print_space_right() to print the padding of
** spaces after the string.
*/

void		format_string(t_flags *x)
{
	char	*str;
	int		length;

	str = va_arg(x->args, char*);
	if (!str)
		str = "(null)";
	length = ft_strlen(str);
	if (x->dot)
		get_precision(x, length);
	if (!x->minus && !x->zero)
		print_space_left(x, length);
	if (x->zero && x->width > length)
		padding(x->width, length, true, x);
	print_output(x, length, str);
	if (x->minus)
		print_space_right(x, length);
}
