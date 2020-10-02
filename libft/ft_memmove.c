/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robitett <robitett@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 18:38:49 by robitett          #+#    #+#             */
/*   Updated: 2020/10/02 16:26:07 by robitett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*ptr_dest;
	const char	*ptr_src;
	char		*dest_plus_n;
	const char	*src_plus_n;

	ptr_dest = dest;
	ptr_src = src;
	dest_plus_n = dest + n;
	src_plus_n = src + n;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest < src)
		while (n--)
			*ptr_dest++ = *ptr_src++;
	else
		while (n--)
			*--dest_plus_n = *--src_plus_n;
	return (dest);
}
