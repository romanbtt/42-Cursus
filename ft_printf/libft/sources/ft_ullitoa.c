/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:31:26 by romanbtt          #+#    #+#             */
/*   Updated: 2020/11/23 21:32:08 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ullitoa_base(unsigned long long int nb, int base)
{
	unsigned long long int	tmp;
	int						size;
	char					*str;

	tmp = nb;
	size = 0;
	if (nb == 0)
		return (ft_strdup("0"));
	while (nb /= base)
		size++;
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	while (tmp > 0)
	{
		if ((tmp % base) < 10)
			str[size--] = (tmp % base) + 48;
		else
			str[size--] = (tmp % base) + 55;
		tmp /= base;
	}
	return (str);
}
