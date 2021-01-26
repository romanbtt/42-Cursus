/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_map_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:26:47 by romanbtt          #+#    #+#             */
/*   Updated: 2021/01/25 20:21:11 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool		is_missing_identifier(t_map map, char *line)
{
	char str[512];

	str[0] = '\0';
	if (is_line_map(line))
		return (false);
	if (!map.width)
		ft_strlcat(str, "Resolution value is missing\n", 29);
	if (!map.fl_rgb)
		ft_strlcat(str, "Floor color value is missing\n", 30);
	if (!map.ceil_rgb)
		ft_strlcat(str, "Ceiling color value is missing\n", 33);
	if (!map.text_no)
		ft_strlcat(str, "North's path texture is missing\n", 33);
	if (!map.text_so)
		ft_strlcat(str, "South's path texture is missing\n", 33);
	if (!map.text_ea)
		ft_strlcat(str, "East's path texture is missing\n", 32);
	if (!map.text_we)
		ft_strlcat(str, "West's path texture is missing\n", 32);
	if (!map.text_sp)
		ft_strlcat(str, "Sprite's path texture is missing\n", 34);
	if (str[0])
		exit_faillure(str);
	else
		return (false);
}

static bool		is_line_map(char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '1' || line[i] == '0')
		return (true);
	return (false); 
}

static bool is_map_identifier(char c)
{
	if ((c == 'N' || c == 'n') ||
		(c == 'S' || c == 's') ||
		(c == 'W' || c == 'w') ||
		(c == 'E' || c == 'e') ||
		(c == 'R' || c == 'r') ||
		(c == 'F' || c == 'f') ||
		(c == 'C' || c == 'c'))
			return (true);
	return (false);
}

static bool		is_empty_line(char *line)
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

void			process_map_file(t_struct *cub, char *file)
{
	int		fd;
	char	*line;

	if ((fd = open(file, O_RDONLY)) < 0)
		exit_faillure("Error : Could't read the map file.\n");
	while (get_next_line(fd, &line))
	{
		if (is_empty_line(line) == true)
			continue;
		else if (is_map_identifier(line[0]) == true && cub->map.count_id < 8)
			get_map_identifier(&cub->map, line);
		else if (is_line_map(line) && !is_missing_identifier(cub->map, line))
			get_line_map(&cub->map, line);
		else
			exit_faillure("The map is not valid.\n");
		free(line);
	}
	if (is_empty_line(line) == false)
	{
		get_line_map(&cub->map, line);
		free(line);
	}
	close(fd);
	is_map_valid(&cub->map, &cub->sprites, &cub->player);
}