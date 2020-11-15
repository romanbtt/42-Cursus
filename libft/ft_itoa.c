/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:15:56 by romanbtt          #+#    #+#             */
/*   Updated: 2020/11/15 16:15:57 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countsize(int n)
{
	size_t count;

	if (n == 0)
		return (1);
	count = 0;
	while (n != 0)
	{
		n /= 10;
		++count;
	}
	return (count);
}

static int		ft_isneg(int n)
{
	if (n < 0)
		return (-1);
	return (1);
}

char			*ft_itoa(int n)
{
	int		neg;
	size_t	i;
	char	*str;
	long	nbr;

	nbr = n;
	i = 0;
	neg = ft_isneg(nbr);
	if (neg == -1)
		i = 1;
	nbr *= neg;
	i += ft_countsize(nbr);
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
		str[i] = '0';
	while (nbr > 0)
	{
		str[i--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (neg == -1)
		str[i] = '-';
	return (str);
}
