/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:17:07 by romanbtt          #+#    #+#             */
/*   Updated: 2020/11/15 16:17:08 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*ptr_s;

	i = 0;
	if (!s || !(ptr_s = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1)))
		return (NULL);
	while (s[i] != '\0')
	{
		ptr_s[i] = f(i, s[i]);
		i++;
	}
	ptr_s[i] = '\0';
	return (ptr_s);
}
