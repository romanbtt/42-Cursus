/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:17:21 by romanbtt          #+#    #+#             */
/*   Updated: 2020/11/15 16:17:22 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char const *set)
{
	while (*set && c != *set)
		set++;
	if (c == *set)
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (ft_isset(*s1, set) && *s1)
		s1++;
	end = ft_strlen(s1);
	while (ft_isset(s1[end], set) && end)
		end--;
	return (ft_substr(s1, 0, end + 1));
}
