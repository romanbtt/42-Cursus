/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_isspace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 10:37:30 by romanbtt          #+#    #+#             */
/*   Updated: 2020/12/19 10:37:56 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countchar(const char *str, int opt_delimit)
{
	size_t i;

	i = 0;
	if (opt_delimit)
	{
		while (str[i] && !ft_isspace(str[i]))
			i++;
	}
	else
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
	}
	return (i);
}

static size_t	ft_countword(const char *str)
{
	size_t i;
	size_t nb_words;

	i = 0;
	nb_words = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	while (str[i])
	{
		while (str[i] && !ft_isspace(str[i]))
			i++;
		nb_words++;
		while (str[i] && ft_isspace(str[i]))
			i++;
	}
	return (nb_words);
}

char			**ft_split_isspace(char const *s)
{
	char	**array;
	size_t	nb_words;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	nb_words = ft_countword(s);
	if (!(array = malloc((nb_words + 1) * sizeof(char *))))
		return (NULL);
	while (i < nb_words)
	{
		s += ft_countchar(s, 0);
		if (!(array[i] = ft_substr(s, 0, ft_countchar(s, 1))))
			return (NULL);
		s += ft_countchar(s, 1) + ft_countchar(s, 0);
		i++;
	}
	array[i] = NULL;
	return (array);
}
