/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:21:35 by romanbtt          #+#    #+#             */
/*   Updated: 2021/01/27 10:24:06 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_line_map(t_struct *cub, char *line)
{
	char	*tmp;
	int		i;

	i = 1;
	cub->map.row_len++;
	while (line[i - 1] != '\n' && line[i - 1] != '\0')
	{
		if (!ft_strchr("012 NSEW", line[i]))
		{
			free(line);
			exit_faillure(cub, "Invalid element in the map\n");
		}
		i++;
	}
	if (cub->map.row_len == 1)
		cub->map.map_1d = ft_strjoin(line, "\n");
	else
	{
		tmp = ft_strdup(cub->map.map_1d);
		free(cub->map.map_1d);
		cub->map.map_1d = ft_strjoin(tmp, ft_strjoin(line, "\n"));
		free(tmp);
	} 
}