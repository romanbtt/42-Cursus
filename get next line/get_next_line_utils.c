/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robitett <robitett@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 16:53:36 by robitett          #+#    #+#             */
/*   Updated: 2020/10/06 02:52:42 by robitett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	char *ptr;

	ptr = s;
	while (n--)
		*ptr++ = '\0';
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	int len;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == c)
			return ((char *)s + len);
		len--;
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	len_s;
	size_t	i;

	if (s == NULL || !(ptr = (char *)malloc(len + 1 * sizeof(char))))
		return (NULL);
	len_s = ft_strlen(s);
	i = 0;
	while (start < len_s && i < len)
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	len;
	size_t i;

	i = 0;
	len = ft_strlen(s) + 1;
	if (!(ptr = malloc(len * sizeof(char))))
		return (NULL);
	while (i < len - 1)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!(ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j])
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	return (ptr);
}