/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:01:52 by romanbtt          #+#    #+#             */
/*   Updated: 2020/11/29 16:07:04 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** The padding() function is used to print padding of space or zero.
** It receives a width value, a length value, a boolean is_zero,
** and the structure.
** While the width is greater than length, we check if the boolean is_zero
** is true or not.
** If it is true, we call the output() function with a '0' and the size of 1.
** If not, we call the output() function with a ' ' and the size of 1.
*/

void	padding(int width, int lenght, bool is_zero, t_flags *x)
{
	while (width > lenght)
	{
		if (is_zero == true)
			output("0", 1, x);
		else
			output(" ", 1, x);
		width--;
	}
}

/*
** The output() function is a function to print several characters from str.
** It receives a char* str character, a size to print and the structure.
** An 'i' variable is declared and used as an index of str.
** While str[i] != '\0' and i is smaller than  size,
** ft_putchar_fd() is called to print the character.
** Then x->count is incremented in the loop.
*/

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
