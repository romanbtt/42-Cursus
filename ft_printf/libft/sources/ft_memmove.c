/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:16:32 by romanbtt          #+#    #+#             */
/*   Updated: 2020/11/15 16:16:33 by romanbtt         ###   ########.fr       */
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
