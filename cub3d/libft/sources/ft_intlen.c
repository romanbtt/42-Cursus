/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:29:47 by romanbtt          #+#    #+#             */
/*   Updated: 2020/11/23 21:30:28 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int nb, int base)
{
	size_t			len;
	unsigned int	nb_u;

	len = 1;
	if (nb < 0)
	{
		nb_u = -nb;
		len = 2;
	}
	else
		nb_u = nb;
	while ((nb_u /= base) > 0)
		len++;
	return (len);
}
