/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:01:43 by romanbtt          #+#    #+#             */
/*   Updated: 2020/11/24 16:47:18 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_string(t_flags *x)
{
	char *str;

	str = va_arg(x->args, char*);
	if (!str)
		str = "(null)";
	if ((x->dot && x->precision > (int)ft_strlen(str)) || x->precision < 0)
		x->precision = (int)ft_strlen(str);
	else if (x->dot && !x->precision)
		x->precision = 0;
	if (!x->minus && x->dot)
		padding(x->width, x->precision, false, x);
	else if (!x->minus)
		padding(x->width, (int)ft_strlen(str), false, x);
	if (x->dot)
		output(str, x->precision, x);
	else
		output(str, ft_strlen(str), x);
	if (x->minus && x->dot)
		padding(x->width, x->precision, false, x);
	else if (x->minus)
		padding(x->width, (int)ft_strlen(str), false, x);
}
