/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:26:13 by romanbtt          #+#    #+#             */
/*   Updated: 2020/11/24 16:47:58 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_percent(t_flags *x)
{
	if (x->zero)
		padding(x->width, 1, true, x);
	else if (!x->minus)
		padding(x->width, 1, false, x);
	output("%", 1, x);
	if (x->minus)
		padding(x->width, 1, false, x);
}
