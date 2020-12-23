/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 18:30:39 by romanbtt          #+#    #+#             */
/*   Updated: 2020/12/23 16:50:35 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define STR_MAP "012 NSEW"

static int	is_map(char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '1' || line[i] == '0')
		return (true);
	return (false); 
}

static int is_missing(t_struct *cub3d, char *line)
{
	if (is_map(line) && (!cub3d->map.resWH[0] || !cub3d->map.floor_color ||
		!cub3d->map.ceiling_color || !cub3d->map.texture_no || !cub3d->map.texture_so ||
		!cub3d->map.texture_we || !cub3d->map.texture_ea || !cub3d->map.texture_sprite))
			exit_faillure("Missing element description.");
	return (1);
}

static int	empty_line(char *line)
{
	int i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == '\n' || line[i] == '\0')
	{
		free(line);
		return (true);
	}
	return (false);
}

static int	is_identifier(char first)
{
	if ((first == 'N' || first == 'n') ||
		(first == 'S' || first == 's') ||
		(first == 'W' || first == 'w') ||
		(first == 'E' || first == 'e') ||
		(first == 'R' || first == 'r') ||
		(first == 'F' || first == 'f') ||
		(first == 'C' || first == 'c'))
			return (true);
	return (false);
}

void		read_file(char *file, t_struct *cub3d)
{
	int		fd;
	char	*line;

	if ((fd = open(file, O_RDONLY)) < 0)
	{
		perror(file);
		exit_faillure("");
	}
	while (get_next_line(fd, &line))
	{
		if (empty_line(line))
			continue;
		else if (is_identifier(line[0]) && cub3d->map.count_id < 8)
			get_identifier(line, cub3d);
		else if (is_map(line) && is_missing(cub3d, line))
			get_map(line, cub3d);
		else
			exit_faillure("The map is not valid.");
		free(line);
	}
	if (!empty_line)
		get_map(line, cub3d);
	is_valid_map(cub3d);
	close(fd);
}
 