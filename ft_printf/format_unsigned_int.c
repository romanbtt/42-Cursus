/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_unsigned_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:15:55 by romanbtt          #+#    #+#             */
/*   Updated: 2020/11/23 20:53:26 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_space_left(t_flags *x, int length, int nb)
{
	if (!x->minus && !x->dot && !x->zero)
		x->count += padding(x->width, length, false);
	if (!x->minus && x->precision)
	{
		if (x->precision < length)
			x->count += padding(x->width, length, false);
		else
			x->count += padding(x->width, x->precision, false);
	}
}

static void	print_zero_left(t_flags *x, int length, int nb)
{
	if (x->zero && !x->dot)
		x->precision = x->width;
	x->count += padding(x->precision, length, true);
}

static void	print_space_right(t_flags *x, int length, int nb)
{
	if (x->minus && length > x->precision)
		x->count += padding(x->width, length, false);
	else if (x->minus && length < x->precision)
		x->count += padding(x->width, x->precision, false);
}

void		format_unsigned_int(t_flags *x)
{
	unsigned int	nb;
	int				length;

	nb = va_arg(x->args, unsigned int);
	length = (int)ft_uintlen(nb, 10);
	if (x->dot && x->precision == 0 && nb == 0)
		x->count += padding(x->width, 0, false);
	else
	{
		print_space_left(x, length, nb);
		print_zero_left(x, length, nb);
		print(ullitoa_base(nb, 10), length, x);
		print_space_right(x, length, nb);
	}
}
