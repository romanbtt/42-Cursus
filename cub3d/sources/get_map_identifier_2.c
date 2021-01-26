/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_identifier_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:32:11 by romanbtt          #+#    #+#             */
/*   Updated: 2021/01/25 15:20:12 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void put_in_rgb(char **array, int rgb[3])
{
	int i;

	i = 0; 
	while (i < 3)
	{
		ft_delspace(array[i]);
		rgb[i] = ft_atoi(array[i]);
		i++;
	}
}

void	identifier_f(char *line, t_map *map)
{
	int i;
	char **array;
	int rgb[3];

	i = -1;
	if (line[++i] == 'F' && ft_isspace(line[1]) && !map->fl_rgb)
		array = ft_split(line + 1, ',');
	else
		exit_faillure("Could't get the floor color values.");
	while (line[++i] != '\0')
	{
		if (!ft_isdigit(line[i]) && !ft_isspace(line[i]) && line[i] != ',')
			exit_faillure("Could't get the floor color values.");
	}
	if (!array[0] || !array[1] || !array[2] || array[3])
		exit_faillure("Could't get the floor color values.");
	put_in_rgb(array, rgb);
	if (rgb[0] < 0 || rgb[0] > 255 || rgb[1] < 0 || rgb[1] > 255 ||
		rgb[2] < 0 || rgb[2] > 255)
		exit_faillure("Could't get the floor color values.");
	map->fl_rgb = (0 << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

void	identifier_c(char *line, t_map *map)
{
	int i;
	char **array;
	int rgb[3];

	i = -1;
	if (line[++i] == 'C' && ft_isspace(line[1]) && !map->ceil_rgb)
		array = ft_split(line + 1, ',');
	else
		exit_faillure("Could't get the ceiling color values.");
	while (line[++i] != '\0')
	{
		if (!ft_isdigit(line[i]) && !ft_isspace(line[i]) && line[i] != ',')
			exit_faillure("Could't get the ceiling color values.");
	}
	if (!array[0] || !array[1] || !array[2] || array[3])
		exit_faillure("Could't get the ceiling color values.");
	put_in_rgb(array, rgb);
	if (rgb[0] < 0 || rgb[0] > 255 || rgb[1] < 0 || rgb[1] > 255 ||
		rgb[2] < 0 || rgb[2] > 255)
		exit_faillure("Could't get the ceiling color values.");
	map->ceil_rgb = (0 << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

void	identifier_r(char *line, t_map *map)
{
	int i;
	char **array;
	
	i = -1;
	if (line[++i] == 'R' && ft_isspace(line[1]) && !map->width)
		array = ft_split_isspace(line + 1);
	else
		exit_faillure("Could't get the resolution values.");
	while (line[++i] != '\0')
	{
		if (!ft_isdigit(line[i]) && !ft_isspace(line[i]))
			exit_faillure("Could't get the resolution values.");
	}
	if (!array[1] || array[2])
		exit_faillure("Could't get the resolution values.");
	map->width = ft_atoi(array[0]);
	map->height = ft_atoi(array[1]); 
}

void	identifier_s_so(char *line, t_map *map)
{
	int i;
	char **array;

	i = 0;
	if (line[0] == 'S' && line[1] == 'O')
	{
		identifier_so(line, map);
		return ;
	}
	if (line[i++] != 'S' || !ft_isspace(line[i++]) ||
		map->text_sp)
	{
		exit_faillure("Could't get the sprite texture.");
	}
	array = ft_split_isspace(line + i);
	if (!array[0] || array[1])
		exit_faillure("Could't get the sprite texture.");
	if (ft_strncmp(array[0] + ft_strlen(array[0]) - 4, ".xpm", 4))
		exit_faillure("Could't get the sprite texture.");
	map->text_sp = ft_strdup(line + i);
}