/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:16:49 by romanbtt          #+#    #+#             */
/*   Updated: 2020/11/15 16:16:49 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countchar(const char *s, char c, int opt_delimit)
{
	size_t i;

	i = 0;
	if (opt_delimit)
	{
		while (s[i] && s[i] != c)
			i++;
	}
	else
	{
		while (s[i] && s[i] == c)
			i++;
	}
	return (i);
}

static size_t	ft_countword(const char *str, char c)
{
	size_t i;
	size_t nb_words;

	i = 0;
	nb_words = 0;
	while (str[i] && str[i] == c)
		i++;
	while (str[i])
	{
		while (str[i] && str[i] != c)
			i++;
		nb_words++;
		while (str[i] && str[i] == c)
			i++;
	}
	return (nb_words);
}

char			**ft_split(char const *s, char c)
{
	char	**array;
	size_t	nb_words;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	nb_words = ft_countword(s, c);
	if (!(array = malloc((nb_words + 1) * sizeof(char *))))
		return (NULL);
	while (i < nb_words)
	{
		s += ft_countchar(s, c, 0);
		if (!(array[i] = ft_substr(s, 0, ft_countchar(s, c, 1))))
			return (NULL);
		s += ft_countchar(s, c, 1) + ft_countchar(s, c, 0);
		i++;
	}
	array[i] = NULL;
	return (array);
}
