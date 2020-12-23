/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shapes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 10:04:24 by romanbtt          #+#    #+#             */
/*   Updated: 2020/12/23 17:54:31 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define WALL_COLOR 0x008a0303
#define COLOR_PLAYER 0x00FFFF00


int		calc_tile_size(t_struct *cub3d)
{
	int ratio_W;
	int ratio_H;

	ratio_W = 0;
	ratio_H = 0;
	ratio_W = cub3d->map.resWH[0] / cub3d->map.max_col;
	ratio_H = cub3d->map.resWH[1] / cub3d->map.nb_row;
	if (ratio_W < ratio_H)
		return (ratio_W);
	return (ratio_H);
}

void	draw_wall_2d(t_struct *cub3d, int tile_row, int tile_col)
{
	int row;
	int col;
	int tile_size;

	tile_size = calc_tile_size(cub3d) * 1;
	row = 0;
	while (row < tile_size)
	{
		col = 0;
		while (col < tile_size)
		{
			my_mlx_pixel_put(cub3d, row + tile_row * tile_size,
				col + tile_col * tile_size, WALL_COLOR);
			col++;
		}
		row++;
	}
}

void	draw_player(t_struct *cub3d, int pos_x, int pos_y)
{
	int radius;
	double angle;
	int x;
	int y;

	radius = 0;
	while (radius < calc_tile_size(cub3d) * 0.08)
	{
		angle = 0;
		while (angle < 2 * M_PI)
		{
			x = radius * cos(angle);
			y = radius * sin(angle);
			my_mlx_pixel_put(cub3d, x + pos_x , y + pos_y, COLOR_PLAYER);
			angle += 0.1;
		}
		radius++;
	}

}
// last update
void draw_line(t_struct *cub3d, int pos_x, int pos_y)
{
	int i;

	i = 0;

	while (i < 40)
	{

		my_mlx_pixel_put(cub3d, pos_x + cos(cub3d->player.rotation_angle) * i, pos_y + sin(cub3d->player.rotation_angle) * i, COLOR_PLAYER);
		i++;
	}
}