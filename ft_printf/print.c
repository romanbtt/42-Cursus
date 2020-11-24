/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:02:13 by romanbtt          #+#    #+#             */
/*   Updated: 2020/11/21 19:26:12 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	padding(int width, int lenght, bool is_zero)
{
	int count;

	count = 0;
	while (width > lenght)
	{
		if (is_zero == true)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		count++;
		width--;
	}
	return (count);
}

void	print(char *str, int size, t_flags *x)
{
	int i;

	i = 0;
	while (str[i] && i < size)
	{
		ft_putchar_fd(str[i++], 1);
		x->count++;
	}
}
