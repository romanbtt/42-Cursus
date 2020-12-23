/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delspace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 18:55:31 by romanbtt          #+#    #+#             */
/*   Updated: 2020/12/19 19:49:07 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_delspace(char *str)
{
	size_t n;
	size_t i;

	i = 0;
	n = 0;
	while (i < ft_strlen(str))
	{
		if (!ft_isspace(str[i]))
			str[n++] = str[i];
		i++;
	}
	str[n] = '\0';
}
