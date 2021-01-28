/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:25:06 by romanbtt          #+#    #+#             */
/*   Updated: 2021/01/27 10:31:57 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define NORTH 1.5 * PI
#define SOUTH 0.5 * PI
#define EAST 2 * PI
#define WEST PI

static void		get_player_angle(t_player *pl , char angle)
{
	if (angle == 'N')
		pl->rot_angle = NORTH;
	else if (angle == 'S')
		pl->rot_angle = SOUTH;
	else if (angle == 'E')
		pl->rot_angle = EAST;
	else if (angle == 'W')
		pl->rot_angle = WEST;
}

void			get_info_player(t_struct *cub, t_player *pl, int row, int col)
{
	if (ft_strchr("NSWE", cub->map.map_2d[row][col]))
	{
		if (!pl->pos.x)
		{
			pl->pos.x = col + 0.5;
			pl->pos.y = row + 0.5;
			get_player_angle(pl, cub->map.map_2d[row][col]);
		}
		else
			exit_faillure(cub, "Player position is set more than once..\n");
	}
}