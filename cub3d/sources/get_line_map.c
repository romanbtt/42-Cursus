/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:21:35 by romanbtt          #+#    #+#             */
/*   Updated: 2021/01/25 15:20:14 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_line_map(t_map *map, char *line)
{
	char	*tmp;
	int		i;

	i = 1;
	map->row_len++;
	while (line[i - 1] != '\n' && line[i - 1] != '\0')
	{
		if (!ft_strchr("012 NSEW", line[i]))
		{
			free(line);
			exit_faillure("Invalid element in the map\n");
		}
		i++;
	}
	if (map->row_len == 1)
		map->map_1d = ft_strjoin(line, "\n");
	else
	{
		tmp = ft_strdup(map->map_1d);
		free(map->map_1d);
		map->map_1d = ft_strjoin(tmp, ft_strjoin(line, "\n"));
		free(tmp);
	} 
}