/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Marvin <Marvin@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 14:08:12 by Marvin            #+#    #+#             */
/*   Updated: 2020/10/20 18:14:16 by Marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
** is_feedline return 1 if a feedline char is founded in the string parameter
** otherwise 0 is returned
*/

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

/*
** The purpose of process_line is to place a line ended by \n or \0 and put the
** remaining of the string inside the static variable remaining.
** i is incremented through the while until \n or \0 is founded.
** ..
** Then two case are possible :
** - If the last character founded is \n :
** We allocate memory to store inside line the string until \n.
** We allocate memory to store the remaining of the string inside temp.
** Then we can free *remainder and make point *remainder to temp.
** If the 1st char of remainder == \0, we (free /set to null) remainder.
** (It means that it was remaining only just one \0 after the \n, in this case
** the program will exit at the next call in the return_value function :case 2)
** Then we can return 1.
** ..
** If the last character founded is \0 :
** We allocate memory to store the last line inside last.
** Then we can free and set to null the pointer remainder and return 0.
*/

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

/*
** return_value is an intermediate step before processing.
** Here we check two case :
** - If ret < 0, we return an error. This is in relation with the return
** of the read function in the get_next_line function.
** - If ret == 0 and remainder[fd] == NULL, we allocate memory to store \0
** inside line and return 0 to tell that we reach EOF.
** If none of these cases append, we can call the process-line function.
*/

static int	return_value(char **remainder, char **line, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (!ret && !remainder[fd])
	{
		*line = ft_strdup("\0");
		return (0);
	}
	return (process_line(&remainder[fd], line));
}

/*
** get_next_line is used to place inside a buffer (*buff) the result
** of the read function. Read will use the dedicated file descriptor (fd)
** given by parameter and the variable BUFFER_SIZE who will determinate how
** many bytes the function will read. Buff will be null terminated each time
** the read function is called. Ret is used to store the read's return.
** (FYI : Read return how many bytes was read)
** ..
** The first if is used to handle the possible errors :
** - If fd < 0 (Fd cannot be negative)
** - If line is NULL (The pointer doesn't exist)
** - If BUFFER_SIZE is < 1 (Read need at least 1 byte to read)
** - If malloc return an NULL pointer (Error, we need to exit)
** ..
** Two stop conditions are possible :
** - read's return is > 0 (means that read reach EOF or an error appended)
** - is_feedline's return is != 0 (mean that a feedline was founded in buff)
** ..
** After each read we check if the static variable remainder[fd] is NULL.
** If YES, we allocate memory to store all the buff.
** (It means that no line has been read before for this specific FD)
** If NO, we concatenate the string in remainder[fd] and the string in buff.
** Then we can free remainder[fd] and make point remainder[fd] to temp.
** ..
** We use fd at the index of remainder to work with several file descriptor.
** OPEN_MAX is the maximum of FD that can be open (Given by limits.h)
** ..
** We make sure to free buff with ft_strdel on the heap before return anything.
** We call another function inside the return to process the line(s) read.
*/

int			get_next_line(int fd, char **line)
{
	static char	*remainder[OPEN_MAX];
	char		*buff;
	char		*temp;
	int			ret;

	if (fd < 0 || !line || BUFFER_SIZE < 1 ||
	!(buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!remainder[fd])
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
