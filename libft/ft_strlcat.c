/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robitett <robitett@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 19:31:43 by robitett          #+#    #+#             */
/*   Updated: 2020/10/02 16:26:40 by robitett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len;
	size_t i;

	i = 0;
	len = (ft_strlen(src));
	while (*dst && size)
	{
		dst++;
		size--;
		i++;
	}
	while (*src && size > 1)
	{
		*dst++ = *src++;
		size--;
	}
	if (size)
		*dst = '\0';
	return (i + len);
}
