/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 15:43:02 by romanbtt          #+#    #+#             */
/*   Updated: 2020/12/23 16:50:32 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define UP cub3d->map.map_2d[row - 1][col]
#define DOWN cub3d->map.map_2d[row + 1][col]
#define RIGHT cub3d->map.map_2d[row][col + 1]
#define LEFT cub3d->map.map_2d[row][col - 1]

#define NORTH M_PI
#define SOUTH M_PI * 2
#define EAST M_PI / 2
#define WEST 3 * M_PI / 2

static void		get_rotation_angle(t_struct *cub3d , char orientation)
{
	if (orientation == 'N')
		cub3d->player.rotation_angle = NORTH;
	else if (orientation == 'S')
		cub3d->player.rotation_angle = SOUTH;
	else if (orientation == 'E')
		cub3d->player.rotation_angle = EAST;
	else if (orientation == 'W')
		cub3d->player.rotation_angle = WEST;
}

static void		get_player(t_struct *cub3d, int row, int col)
{
	if (ft_strchr("NSWE", cub3d->map.map_2d[row][col]))
	{
		if (!cub3d->player.pos_XY[0])
		{
			cub3d->player.pos_XY[0] = row;
			cub3d->player.pos_XY[1] = col;
			get_rotation_angle(cub3d, cub3d->map.map_2d[row][col]);
		}
		else
			exit_faillure("Player position was set more than once.\n");
	}
}

static int		is_char_allowed(char c)
{
	if (!c)
		return (0);
	if (ft_strchr("012NSEW", c))
		return (true);
	return (false);
}

static void check_sides(t_struct *cub3d, int row, int col, int nb_col)
{
	if (((row == 0 || row == cub3d->map.nb_row - 1) || (col == 0 ||
		col == nb_col - 1)) && (!(ft_strchr("1 ", cub3d->map.map_2d[row][col]))))
				exit_faillure("The map is not valid2.\n");
	else if ((row > 0 && row < cub3d->map.nb_row - 1) &&
		(col > 0 && col < nb_col - 1) && (ft_strchr("02NSWE", cub3d->map.map_2d[row][col])) &&
		((!(is_char_allowed(UP))) ||
		(!(is_char_allowed(DOWN))) ||
		(!(is_char_allowed(RIGHT))) ||
		(!(is_char_allowed(LEFT)))))
			exit_faillure("The map is not valid1.\n");
}
 
void		is_valid_map(t_struct *cub3d)
{
	int row;
	int col;
	int nb_col;

	row = 0;
	cub3d->map.map_2d = ft_split(cub3d->map.map, '\n');
	while (row < cub3d->map.nb_row)
	{ 
		col = 0;
		nb_col = ft_strlen(cub3d->map.map_2d[row]);
		if (nb_col > cub3d->map.max_col)
			cub3d->map.max_col = nb_col;
		while (col < nb_col)
		{
			check_sides(cub3d, row, col, nb_col);
			get_player(cub3d, row, col);
			col++;
		}
		row++;
	}
	if (!cub3d->player.pos_XY[0])
		exit_faillure("Player position was not set.\n");
}