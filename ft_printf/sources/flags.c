/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:01:32 by romanbtt          #+#    #+#             */
/*   Updated: 2020/12/02 08:38:13 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** flag_dot() is called when '.' is founded.
** We activate the flag x->dot.
** If '*' is founded at format[++x->idx] :
** 		We store the precision value inside x->precision.
** 		If x->precision is positive, we desactivate x->zero.
** Else :
**		If ft_digit(format[x->idx]) return 1, we desactivate x->zero.
**		While format[x->idx] is a digit, we store the precision value
**		inside x->precision.
*/

void	flag_dot(const char *format, t_flags *x)
{
	x->dot = true;
	if (format[++x->idx] == '*')
	{
		x->precision = va_arg(x->args, int);
		if (x->precision >= 0)
			x->zero = false;
		x->idx++;
	}
	else
	{
		if (ft_isdigit(format[x->idx]))
			x->zero = false;
		while (ft_isdigit(format[x->idx]))
		{
			x->precision = (x->precision * 10) + (format[x->idx] - '0');
			x->idx++;
		}
	}
}

/*
** flag_zero() is called when '0' is founded.
** While format[x->idx] == '0', we increment x->idx to get rid of serie of '0'
** If x->minus is desactivate, we can activate the flag x->zero.
** If format[x->idx] == '-', we call flag_minus().
*/

void	flag_zero(const char *format, t_flags *x)
{
	while (format[x->idx] == '0')
		x->idx++;
	if (!x->minus)
		x->zero = true;
	if (format[x->idx] == '-')
		flag_minus(format, x);
}

/*
** flag_wildcard() is called to get the width value.
** If format[x->idx] == '*' :
** We store the width value inside x->width.
** If x-width is nagative :
**		We activate x->minus, desactivate x->zero and convert
**		x->zidth in positive.
** Else :
** 		While format[x->idx] is a digit, we store the width value
**		inside x->width.
*/

void	flag_wildcard(const char *format, t_flags *x)
{
	if (format[x->idx] == '*')
	{
		x->width = va_arg(x->args, int);
		if (x->width < 0)
		{
			x->minus = true;
			x->zero = false;
			x->width = -x->width;
		}
		x->idx++;
	}
	else
	{
		while (ft_isdigit(format[x->idx]))
		{
			x->width = (x->width * 10) + (format[x->idx] - '0');
			x->idx++;
		}
	}
}

/*
** flag_minus() is called when '-' is founded.
** While format[x->idx] == '-', we increment x->idx to get rid of serie of '-'
** We activate x->minus and desactivate x->zero.
** If format[x->idx] == '0', we call flag_zero().
*/

void	flag_minus(const char *format, t_flags *x)
{
	while (format[x->idx] == '-')
		x->idx++;
	x->minus = true;
	x->zero = false;
	if (format[x->idx] == '0')
		flag_zero(format, x);
}
