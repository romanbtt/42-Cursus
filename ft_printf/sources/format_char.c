/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:01:38 by romanbtt          #+#    #+#             */
/*   Updated: 2020/11/30 22:19:09 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** First, we declare a char 'c'.
** If x->minus is not active, then we print padding of spaces of the difference
** of x->width and 1.
** We call ft_putchar_fd() to print the char and increment x->count.
** If x->minus is active, then we print padding of spaces of the difference of
** x->width and 1.
*/

void	format_char(t_flags *x)
{
	char c;

	c = va_arg(x->args, int);
	if (!x->minus)
		padding(x->width, 1, false, x);
	ft_putchar_fd(c, 1);
	x->count++;
	if (x->minus)
		padding(x->width, 1, false, x);
}
