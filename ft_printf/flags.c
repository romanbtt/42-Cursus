/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:01:32 by romanbtt          #+#    #+#             */
/*   Updated: 2020/11/16 17:54:33 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_digit(const char *format, t_flags *x)
{
	while (ft_isdigit(format[x->idx]))
	{
		if (x->dot)
		{
			x->precision = (x->precision * 10) + (format[x->idx] - 48);
		}	
		else
			x->width = (x->width * 10) + (format[x->idx] - 48);
		x->idx++;
	}
	x->idx--;
	if (format)
			return ;
}

void	flag_dot(const char *format, t_flags *x)
{
		x->dot = 1;
		if (format)
			return ;
}

void	flag_zero(const char *format, t_flags *x)
{
	if (format[x->idx] == '0' && !x->minus && !x->width)
		x->zero = 1;
}

void	flag_wildcard(const char *format, t_flags *x)
{
	if (x->dot)
		x->precision = va_arg(x->args, int);
	else
		x->width = va_arg(x->args, int);
	if (x->width < 0)
	{
		x->minus = -x->width;
		x->zero = 0;
		x->width = 0;
	}
	if (format)
		return ;
}

void	flag_minus(const char *format, t_flags *x)
{
	x->minus = 1;
	x->zero = 0;
	if (format)
		return ;
}
