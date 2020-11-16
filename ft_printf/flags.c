/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:12:48 by robitett          #+#    #+#             */
/*   Updated: 2020/11/16 09:53:35 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_digit(const char *format, t_flags *x)
{
	x->width = 0;
	while (ft_isdigit(format[x->idx]))
	{
		x->width = (x->width * 10) + (format[x->idx] - 48);
		x->idx++;
	}
	x->idx--;
}

void	flag_dot(const char *format, t_flags *x)
{
	x->idx++;
	if (format[x->idx] == '*')
	{
		x->precision = va_arg(x->args, int);
		x->idx++;
	}
	else
	{
		x->precision = 0;
		while (ft_isdigit(format[x->idx]))
		{
			x->precision = (x->precision * 10) + (format[x->idx] - 48);
			x->idx++;
		}
		x->idx--;
	}
}

void	flag_zero(const char *format, t_flags *x)
{
	if (format[x->idx] == '0' && !x->minus && !x->width)
		x->zero = 1;
}

void	flag_wildcard(const char *format, t_flags *x)
{
	x->width = va_arg(x->args, int);
	x->wildcard = 1;
	if (x->width < 0)
	{
		x->minus = -x->width;
		x->zero = 0;
		x->width = 0;
	}
}

void	flag_minus(const char *format, t_flags *x)
{
	x->minus = 0;
	x->zero = 0;
	x->idx++;
	while (ft_isdigit(format[x->idx]))
	{
		x->minus = (x->minus * 10) + (format[x->idx] - 48);
		x->idx++;
	}
	x->idx--;
}


