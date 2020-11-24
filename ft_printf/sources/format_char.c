/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:01:38 by romanbtt          #+#    #+#             */
/*   Updated: 2020/11/24 16:52:21 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_char(t_flags *x)
{
	char c[2];

	c[0] = va_arg(x->args, int);
	if (!x->minus)
		padding(x->width, 1, false, x);
	output(c, 1, x);
	if (x->minus)
		padding(x->width, 1, false, x);
}
