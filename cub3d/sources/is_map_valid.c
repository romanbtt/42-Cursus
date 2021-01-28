/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:22:42 by romanbtt          #+#    #+#             */
/*   Updated: 2021/01/27 21:25:42 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define UP cub->map.map_2d[row - 1][col]
#define DOWN cub->map.map_2d[row + 1][col]
#define RIGHT cub->map.map_2d[row][col + 1]
#define LEFT cub->map.map_2d[row][col - 1]
#define UP_LEFT cub->map.map_2d[row - 1][col - 1]
#define DOWN_LEFT cub->map.map_2d[row + 1][col - 1]
#define UP_RIGHT cub->map.map_2d[row - 1][col + 1]
#define DOWN_RIGHT cub->map.map_2d[row + 1][col + 1]

static bool		is_char_allowed(char c)
{
	if (!c)
		return (0);
	if (ft_strchr("012NSEW", c))
		return (true);
	return (false);
}

static void check_sides_map(t_struct *cub, int row, int col, int curr_col_len)
{
	if (((row == 0 || row == cub->map.row_len - 1) || (col == 0 ||
		col == curr_col_len - 1)) && (!(ft_strchr("1 ", cub->map.map_2d[row][col]))))
		{
			exit_faillure(cub, "The map is not valid.\n");
		}
	else if ((row > 0 && row < cub->map.row_len - 1) &&
		(col > 0 && col < curr_col_len - 1) &&
		(ft_strchr("02NSWE", cub->map.map_2d[row][col])) &&
		((!(is_char_allowed(UP))) || (!(is_char_allowed(DOWN))) ||
		(!(is_char_allowed(RIGHT))) || (!(is_char_allowed(LEFT))) ||
		(!(is_char_allowed(UP_LEFT))) || (!(is_char_allowed(DOWN_LEFT))) ||
		(!(is_char_allowed(UP_RIGHT))) || (!(is_char_allowed(DOWN_RIGHT)))))
		{
			exit_faillure(cub, "The map is not valid.\n");
		}			
}

void		is_map_valid(t_struct *cub, t_map *map, t_player *pl)
{
	int row;
	int col;
	int curr_col_len;

	row = 0;
	map->map_2d = ft_split(map->map_1d, '\n');
	while (row < map->row_len)
	{
		col = 0;
		curr_col_len = ft_strlen(map->map_2d[row]);
		while (col < curr_col_len)
		{
			check_sides_map(cub, row, col, curr_col_len);
			get_info_player(cub, pl, row, col);
			if (map->map_2d[row][col] == '2')
				map->sp_qty++;
			col++;
		}
		row++;
		if (curr_col_len > map->col_len)
			map->col_len = curr_col_len;
	}
	if (!pl->pos.x || !pl->pos.y)
		exit_faillure(cub, "Player position is not set on the map.\n");
}
