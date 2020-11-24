/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:39:12 by romanbtt          #+#    #+#             */
/*   Updated: 2020/11/23 20:50:19 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_pointer(t_flags *x)
{
	char	*str;
	int		i;

	i = 0;
	str = ullitoa_base(va_arg(x->args, unsigned long long int), 16);
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	if (!x->minus)
		x->count += padding(x->width, ft_strlen(str) + 2, false);
	print("0x", 2, x);
	print(str, ft_strlen(str), x);
	if (x->minus)
		x->count += padding(x->width, ft_strlen(str) + 2, false);
	free(str);
}
