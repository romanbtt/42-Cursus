/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:26:13 by romanbtt          #+#    #+#             */
/*   Updated: 2020/11/30 22:15:34 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** If x->minus and x->zero are not active, we print padding of spaces of the
** difference between x->width and 1.
** If the flag  x->zero is active, then we print padding of zeros of the
** difference between x->width and 1. (length of '%').
** Then we print the '%' character with output().
** Then if x->minus is active, we print padding of spaces of the
** difference between x->width and 1.
*/

void	format_percent(t_flags *x)
{
	if (!x->minus && !x->zero)
		padding(x->width, 1, false, x);
	if (x->zero)
		padding(x->width, 1, true, x);
	output("%", 1, x);
	if (x->minus)
		padding(x->width, 1, false, x);
}
