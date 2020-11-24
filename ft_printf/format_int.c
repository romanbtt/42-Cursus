/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:18:44 by romanbtt          #+#    #+#             */
/*   Updated: 2020/11/23 20:48:56 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			print_space_left(t_flags *x, int length, int nb)
{
	if (!x->minus && !x->dot && !x->zero)
		x->count += padding(x->width, length, false);
	if (!x->minus && x->precision)
	{
		if (x->precision < length)
			x->count += padding(x->width, length, false);
		else if (nb >= 0)
			x->count += padding(x->width, x->precision, false);
		else
			x->count += padding(x->width, x->precision + 1, false);
	}
}

static unsigned int	print_zero_left(t_flags *x, int length, int nb)
{
	unsigned int nb_u;

	if (x->zero && !x->dot)
	{
		if (nb >= 0)
			x->precision = x->width;
		else
			x->precision = x->width - 1;
	}
	if (nb < 0)
	{
		print("-", 1, x);
		nb_u = nb * -1;
		x->count += padding(x->precision, length - 1, true);
	}
	else
	{
		x->count += padding(x->precision, length, true);
		nb_u = nb;
	}
	return (nb_u);
}

static void			print_space_right(t_flags *x, int length, int nb)
{
	if (x->minus && length > x->precision)
		x->count += padding(x->width, length, false);
	else if (x->minus && length < x->precision)
	{
		if (nb < 0)
			x->count += padding(x->width, x->precision + 1, false);
		else
			x->count += padding(x->width, x->precision, false);
	}
}

void				format_int(t_flags *x)
{
	int				nb;
	int				length;
	unsigned int	nb_u;

	nb = va_arg(x->args, int);
	length = (int)ft_intlen(nb, 10);
	if (x->dot && x->precision == 0 && nb == 0)
		x->count += padding(x->width, 0, false);
	else
	{
		print_space_left(x, length, nb);
		nb_u = print_zero_left(x, length, nb);
		print(ullitoa_base(nb_u, 10), length, x);
		print_space_right(x, length, nb);
	}
}
