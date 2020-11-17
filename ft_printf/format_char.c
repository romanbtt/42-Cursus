/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:01:38 by romanbtt          #+#    #+#             */
/*   Updated: 2020/11/16 17:23:16 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_char(t_flags *x)
{
	char c;

	c = va_arg(x->args, int);
	if (!x->minus)
		padding(x->width, 1, x);
	ft_putchar_fd(c, 1);
	if (x->minus)
		padding(x->width, 1, x);
}
