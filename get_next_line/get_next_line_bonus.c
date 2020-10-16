/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robitett <robitett@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 14:08:12 by robitett          #+#    #+#             */
/*   Updated: 2020/10/07 02:00:04 by robitett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	is_feedline(const char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] != '\n')
		return (0);
	return (1);
}

static int	process_line(char **remainder, char **line)
{
	int		i;
	char	*temp;

	i = 0;
	while ((*remainder)[i] != '\n' && (*remainder)[i] != '\0')
		i++;
	if ((*remainder)[i] == '\n')
	{
		*line = ft_substr(*remainder, 0, i);
		temp = ft_strdup(&((*remainder)[i + 1]));
		free(*remainder);
		*remainder = temp;
		if ((*remainder)[0] == '\0')
			ft_strdel(remainder);
		return (1);
	}
	else
	{
		*line = ft_strdup(*remainder);
		ft_strdel(remainder);
		return (0);
	}
}

static int	return_value(char **remainder, char **line, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && remainder[fd] == NULL)
	{
		*line = ft_strdup("\0");
		return (0);
	}
	return (process_line(&remainder[fd], line));
}

int			get_next_line(int fd, char **line)
{
	static char	*remainder[OPEN_MAX];
	char		*buff;
	char		*temp;
	int			ret;

	if (fd < 0 || line == 0 || BUFFER_SIZE < 1 ||
	!(buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (remainder[fd] == NULL)
			remainder[fd] = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(remainder[fd], buff);
			free(remainder[fd]);
			remainder[fd] = temp;
		}
		if (is_feedline(buff))
			break ;
	}
	ft_strdel(&buff);
	return (return_value(remainder, line, ret, fd));
}
