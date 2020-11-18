/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:39:12 by romanbtt          #+#    #+#             */
/*   Updated: 2020/11/17 21:15:30 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void format_pointer(t_flags *x)
{
	char *str;
	char *test;
	int i;

	i = 0;
	test = ullitoa_base(va_arg(x->args, unsigned long long int), 16);
	str = ft_strjoin("0x", test);
	while (str[i++])
		str[i] = ft_tolower(str[i]);
	if (!x->minus)
		padding(x->width, ft_strlen(str), x);
	print(str, ft_strlen(str), x);
	if (x->minus)
		padding(x->width, ft_strlen(str), x);
	free(str);
}