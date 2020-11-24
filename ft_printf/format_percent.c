/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:26:13 by romanbtt          #+#    #+#             */
/*   Updated: 2020/11/23 20:49:40 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_percent(t_flags *x)
{
	if (x->zero)
		x->count += padding(x->width, 1, true);
	else if (!x->minus)
		x->count += padding(x->width, 1, false);
	ft_putchar_fd('%', 1);
	x->count++;
	if (x->minus)
		x->count += padding(x->width, 1, false);
}
