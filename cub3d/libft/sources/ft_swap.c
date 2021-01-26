/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 18:03:34 by romanbtt          #+#    #+#             */
/*   Updated: 2021/01/18 18:06:08 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_swap(void *a, void *b, size_t len)
{
	size_t i;
    unsigned char	*p;
	unsigned char	*q;
	unsigned char	tmp;
	
	i = 0;
	*p = a;
	*q = b;
	while (i != len)
	{
		tmp = p[i];
        p[i] = q[i];
        q[i] = tmp;
		i++;
	}
}