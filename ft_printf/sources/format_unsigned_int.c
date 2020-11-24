/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_unsigned_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:15:55 by romanbtt          #+#    #+#             */
/*   Updated: 2020/11/24 16:46:44 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_space_left(t_flags *x, int length)
{
	if (!x->minus && !x->dot && !x->zero)
		padding(x->width, length, false, x);
	if (!x->minus && x->precision)
	{
		if (x->precision < length)
			padding(x->width, length, false, x);
		else
			padding(x->width, x->precision, false, x);
	}
}

static void	print_zero_left(t_flags *x, int length)
{
	if (x->zero && !x->dot)
		x->precision = x->width;
	padding(x->precision, length, true, x);
}

static void	print_space_right(t_flags *x, int length)
{
	if (x->minus && length > x->precision)
		padding(x->width, length, false, x);
	else if (x->minus && length < x->precision)
		padding(x->width, x->precision, false, x);
}

void		format_unsigned_int(t_flags *x)
{
	unsigned int	nb;
	int				length;

	nb = va_arg(x->args, unsigned int);
	length = (int)ft_uintlen(nb, 10);
	if (x->dot && x->precision == 0 && nb == 0)
		padding(x->width, 0, false, x);
	else
	{
		print_space_left(x, length);
		print_zero_left(x, length);
		output(ullitoa_base(nb, 10), length, x);
		print_space_right(x, length);
	}
}
