/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:31:26 by romanbtt          #+#    #+#             */
/*   Updated: 2020/12/02 10:55:13 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*put_in_str(unsigned long long int nb, int base, int size, char *s)
{
	while (nb != 0)
	{
		if ((nb % base) < 10)
			s[size - 1] = (nb % base) + 48;
		else
			s[size - 1] = (nb % base) + 55;
		nb /= base;
		size--;
	}
	return (s);
}

char		*ft_ullitoa_base(unsigned long long int nb, int base)
{
	unsigned long long int	tmp;
	int						size;
	char					*str;

	tmp = nb;
	size = 0;
	str = 0;
	if (nb == 0)
		return (ft_strdup("0"));
	while (nb)
	{
		nb /= base;
		size++;
	}
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	str = put_in_str(tmp, base, size, str);
	return (str);
}
