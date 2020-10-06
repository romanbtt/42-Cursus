/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robitett <robitett@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 14:08:12 by robitett          #+#    #+#             */
/*   Updated: 2020/10/06 13:27:17 by robitett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		process_line(char **remainder, char **line, int ret)
{
	int i;
	char *temp;

	i = 0;
	if (ret < 0)
		return (-1);
	else if (ret == 0 && *remainder[0] == '\0')
		return (0);
	else
	{
		while((*remainder)[i] != '\n' && (*remainder)[i] != '\0')
			i++;
		if ((*remainder)[i] == '\n')
		{
			*line = ft_substr(*remainder, 0, i);
			temp = ft_strdup((&(*remainder)[i + 1]));
			ft_bzero(remainder, ft_strlen(*remainder));
			*remainder = temp;
		}
		else
		{
			*line = ft_strdup(*remainder);
			*remainder[0] = '\0';
		}	
		return (1);
	}
}

int 	get_next_line(int fd, char **line)
{
	static char *remainder[MAX_FILE];
	char buff[BUFFER_SIZE + 1];
	char *temp;
	int ret;
	
	ft_bzero(buff, BUFFER_SIZE + 1);
	if (fd < 0 || !line)
		return (-1);
	while (!ft_strrchr(buff, '\n') && ((ret = read(fd, buff, BUFFER_SIZE)) > 0))
	{
		buff[ret] = '\0';
		if (remainder[fd] == NULL)
			remainder[fd] = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(remainder[fd], buff);
			ft_bzero(remainder, ft_strlen(remainder[fd]));
			remainder[fd] = temp;
		}
	}
	return (process_line(&remainder[fd], line, ret));
}
