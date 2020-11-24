/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:01:52 by romanbtt          #+#    #+#             */
/*   Updated: 2020/11/24 16:45:46 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	padding(int width, int lenght, bool is_zero, t_flags *x)
{
	int count;

	count = 0;
	while (width > lenght)
	{
		if (is_zero == true)
			output("0", 1, x);
		else
			output(" ", 1, x);
		width--;
	}
}

void	output(char *str, int size, t_flags *x)
{
	int i;

	i = 0;
	while (str[i] && i < size)
	{
		ft_putchar_fd(str[i++], 1);
		x->count++;
	}
}
