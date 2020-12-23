/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_identifier_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:45:15 by romanbtt          #+#    #+#             */
/*   Updated: 2020/12/23 16:50:28 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	identifier_so(char *line, t_struct *cub3d)
{
	int i;
	char **array;

	i = -1;
	if (line[++i] != 'S' || line[++i] != 'O' || !ft_isspace(line[++i]) ||
		cub3d->map.texture_so)
		exit_faillure("Could't get the south texture.");
	array = ft_split_isspace(line + i);
	if (!array[0] || array[1])
		exit_faillure("Could't get the south texture.");
	if (ft_strncmp(array[0] + ft_strlen(array[0]) - 4, ".xpm", 4))
		exit_faillure("Could't get the south texture.");
	cub3d->map.texture_so = ft_strdup(line + i);
}

void	identifier_n(char *line, t_struct *cub3d)
{ 
	int i;
	char **array;

	i = -1;
	if (line[++i] != 'N' || line[++i] != 'O' || !ft_isspace(line[++i]) ||
		cub3d->map.texture_no)
		exit_faillure("Could't get the north texture.");
	array = ft_split_isspace(line + i);
	if (!array[0] || array[1])
		exit_faillure("Could't get the north texture.");
	if (ft_strncmp(array[0] + ft_strlen(array[0]) - 4, ".xpm", 4))
		exit_faillure("Could't get the north texture.");
	cub3d->map.texture_no = ft_strdup(line + i);
}

void	identifier_s_so(char *line, t_struct *cub3d)
{
	int i;
	char **array;

	i = -1;
	if (line[0] == 'S' && line[1] == 'O')
	{
		identifier_so(line, cub3d);
		return ;
	}
	if (line[++i] != 'S' || !ft_isspace(line[++i]) || cub3d->map.texture_sprite)
		exit_faillure("Could't get the sprite texture.");
	array = ft_split_isspace(line + i);
	if (!array[0] || array[1])
		exit_faillure("Could't get the sprite texture.");
	if (ft_strncmp(array[0] + ft_strlen(array[0]) - 4, ".xpm", 4))
		exit_faillure("Could't get the sprite texture.");
	cub3d->map.texture_sprite = ft_strdup(line + i);
}

void	identifier_w(char *line, t_struct *cub3d)
{
	int i;
	char **array;

	i = -1;
	if (line[++i] != 'W' || line[++i] != 'E' || !ft_isspace(line[++i]) ||
		cub3d->map.texture_we)
		exit_faillure("Could't get the west texture.");
	array = ft_split_isspace(line + i);
	if (!array[0] || array[1])
		exit_faillure("Could't get the west texture.");
	if (ft_strncmp(array[0] + ft_strlen(array[0]) - 4, ".xpm", 4))
		exit_faillure("Could't get the west texture.");
	cub3d->map.texture_we = ft_strdup(line + i);
}

void	identifier_e(char *line, t_struct *cub3d)
{
	int i;
	char **array;

	i = -1;
	if (line[++i] != 'E' || line[++i] != 'A' || !ft_isspace(line[++i]) ||
		cub3d->map.texture_ea)
		exit_faillure("Could't get the east texture.");
	array = ft_split_isspace(line + i);
	if (!array[0] || array[1])
		exit_faillure("Could't get the east texture.");
	if (ft_strncmp(array[0] + ft_strlen(array[0]) - 4, ".xpm", 4))
		exit_faillure("Could't get the east texture.");
	cub3d->map.texture_ea = ft_strdup(line + i);
}