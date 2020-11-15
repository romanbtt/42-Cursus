/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:16:53 by romanbtt          #+#    #+#             */
/*   Updated: 2020/11/15 16:16:54 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	void	*ptr;
	size_t	len;

	len = ft_strlen(s) + 1;
	if (!(ptr = malloc(len * sizeof(char))))
		return (NULL);
	ft_strlcpy(ptr, s, len);
	return (ptr);
}
