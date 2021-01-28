/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_identifier_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:09:15 by romanbtt          #+#    #+#             */
/*   Updated: 2021/01/27 21:11:39 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define STR_ID_MAJ "NSWERFC"
#define STR_ID_MIN "nswerfc"

void	identifier_n(t_struct *cub, t_map *map, char *line)
{ 
	int i;
	char **array;

	i = 0;
	if (line[i++] != 'N' || line[i++] != 'O' ||
		line[i++] != ' ' || map->text_no)
		{
			exit_faillure(cub, "Could't get the north texture.");
		}
	while (ft_isspace(line[i]))
		i++;
	array = ft_split_isspace(line + i);
	if (!array[0] || array[1])
		exit_faillure(cub, "Could't get the north texture.");
	//if (ft_strncmp(array[0] + ft_strlen(array[0]) - 4, ".xpm", 4))
		//exit_faillure(cub, "Could't get the north texture.");
	map->text_no = ft_strdup(line + i);
}

void	identifier_so(t_struct *cub, t_map *map, char *line)
{
	int i;
	char **array;

	i = 0;
	if (line[i++] != 'S' || line[i++] != 'O' ||
		line[i++] != ' ' || map->text_so)
		{
			exit_faillure(cub, "Could't get the south texture.");
		}
	while (ft_isspace(line[i]))
		i++;
	array = ft_split_isspace(line + i);
	if (!array[0] || array[1])
		exit_faillure(cub, "Could't get the south texture.");
//	if (ft_strncmp(array[0] + ft_strlen(array[0]) - 4, ".xpm", 4))
	//	exit_faillure(cub, "Could't get the south texture.");
	map->text_so = ft_strdup(line + i);
}

void	identifier_e(t_struct *cub, t_map *map, char *line)
{
	int i;
	char **array;

	i = 0;
	if (line[i++] != 'E' || line[i++] != 'A' ||
		line[i++] != ' ' || map->text_ea)
		{
			exit_faillure(cub, "Could't get the east texture.");
		}
	while (ft_isspace(line[i]))
		i++;
	array = ft_split_isspace(line + i);
	if (!array[0] || array[1])
		exit_faillure(cub, "Could't get the east texture.");
//	if (ft_strncmp(array[0] + ft_strlen(array[0]) - 4, ".xpm", 4))
	//	exit_faillure(cub, "Could't get the east texture.");
	map->text_ea = ft_strdup(line + i);
}

void	identifier_w(t_struct *cub, t_map *map, char *line)
{
	int i;
	char **array;

	i = 0;
	if (line[i++] != 'W' || line[i++] != 'E' ||
		line[i++] != ' ' || map->text_we)
		{
			exit_faillure(cub, "Could't get the west texture.");
		}
	while (ft_isspace(line[i]))
		i++;
	array = ft_split_isspace(line + i);
	if (!array[0] || array[1])
		exit_faillure(cub, "Could't get the west texture.");
	//if (ft_strncmp(array[0] + ft_strlen(array[0]) - 4, ".xpm", 4))
	//	exit_faillure(cub, "Could't get the west texture.");
	map->text_we = ft_strdup(line + i);
}

void	get_map_identifier(t_struct *cub, char *line)
{
	int						i;
	static t_array_func_id	func_id[7] = {identifier_n, identifier_s_so,
		identifier_w, identifier_e, identifier_r, identifier_f, identifier_c};

	i = 0;
	while (line[0] != STR_ID_MAJ[i] && line[0] != STR_ID_MIN[i])
		i++;
	(*func_id[i])(cub, &cub->map, line);
	cub->map.count_id++;
}