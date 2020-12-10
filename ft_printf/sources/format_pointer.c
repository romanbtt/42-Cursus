/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:39:12 by romanbtt          #+#    #+#             */
/*   Updated: 2020/11/30 22:32:48 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** First, we declare an int 'i' as an index to transform each char of
** str to lower case.
** Str is declared to store the address converted in str with the help
** of ullitoa_base().
** Length is used to store the length of the string.
** If ptr == 0 and x->dot is active and x->precision value is 0,
** we set length to 0.
** Else, we set length to the length of str.
** The while loop is used to transform the str in lowercase since
** ullitoa_base() return uppercase char.
** If x->minus is not active, then we print padding of spaces of the
** difference of x->width and length + 2.
** We have to put (+2) because we have to print an "0x" since an
** address of the memory starts always with that.
** Then we print the "0x" string.
** If x->precision value is different than 0, we print a padding of zeros
** of the difference of x->precision and length.
** If length is different than 0, we print str.
** If x->minus is active, we print padding of space of the difference
** of x->minus and length + 2.
** Finally, we freed str because it was allocated on the heap
** with ullitoa_base().
*/

#include <stdio.h>

void	format_pointer(t_flags *x)
{
	int						i;
	char					*str;
	char					length;
	unsigned long long int	ptr;

	ptr = va_arg(x->args, unsigned long long int);
	i = 0;
	str = ft_ullitoa_base(ptr, 16);
	if (!ptr && x->dot && !x->precision)
		length = 0;
	else
		length = ft_strlen(str);
	while ((str[i] = ft_tolower(str[i])))
		i++;
	if (!x->minus)
		padding(x->width, length + 2, false, x);
	output("0x", 2, x);
	if (x->precision)
		padding(x->precision, length, true, x);
	if (length)
		output(str, length, x);
	if (x->minus)
		padding(x->width, length + 2, false, x);
	free(str);
}
