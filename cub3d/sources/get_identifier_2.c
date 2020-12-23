/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_identifier_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:52:11 by romanbtt          #+#    #+#             */
/*   Updated: 2020/12/23 16:50:29 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int static *put_in_rgb(char **array)
{
	int i;
	int rgb[3];

	i = 0; 
	while (i < 3)
	{
		ft_delspace(array[i]);
		rgb[i] = ft_atoi(array[i]);
		i++;
	}
	return (rgb);
}

void	identifier_r(char *line, t_struct *cub3d)
{
	int i;
	char **array;
	
	i = -1;
	if (line[++i] == 'R' && ft_isspace(line[1]) && !cub3d->map.resWH[0])
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
	cub3d->map.resWH[0] = ft_atoi(array[0]);
	cub3d->map.resWH[1] = ft_atoi(array[1]); 
}

void	identifier_f(char *line, t_struct *cub3d)
{
	int i;
	char **array;
	int *rgb;

	i = -1;
	if (line[++i] == 'F' && ft_isspace(line[1]) && !cub3d->map.floor_color)
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
	rgb = put_in_rgb(array);
	if (rgb[0] < 0 || rgb[0] > 255 || rgb[1] < 0 || rgb[1] > 255 ||
		rgb[2] < 0 || rgb[2] > 255)
		exit_faillure("Could't get the floor color values.");
	cub3d->map.floor_color = create_trgb(0, rgb[0], rgb[1], rgb[2]);
}

void	identifier_c(char *line, t_struct *cub3d)
{
	int i;
	char **array;
	int *rgb;

	i = -1;
	if (line[++i] == 'C' && ft_isspace(line[1]) && !cub3d->map.ceiling_color)
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
	rgb = put_in_rgb(array);
	if (rgb[0] < 0 || rgb[0] > 255 || rgb[1] < 0 || rgb[1] > 255 ||
		rgb[2] < 0 || rgb[2] > 255)
		exit_faillure("Could't get the ceiling color values.");
	cub3d->map.ceiling_color = create_trgb(0, rgb[0], rgb[1], rgb[2]);
}
