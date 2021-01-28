/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_projection_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 22:18:20 by romanbtt          #+#    #+#             */
/*   Updated: 2021/01/27 15:03:46 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_wall(t_struct *cub, t_wall *wall, int col)
{
	int row;
	unsigned int color;

	row = wall->top_strp;
	if (cub->ray[col].hit_vert)
		wall->offset_x = (int)cub->ray[col].hit_y % cub->map.tile_size;
	else
		wall->offset_x = (int)cub->ray[col].hit_x % cub->map.tile_size;
	wall->offset_x *= cub->text.curr.width / cub->map.tile_size;
	while (row < wall->btm_strp)
	{
		wall->top_dist = row + (wall->proj_wall_height / 2) - (cub->map.height / 2);
		wall->offset_y = wall->top_dist * (cub->text.curr.height /
			wall->proj_wall_height);
		color = pick_pixel(&cub->text.curr, wall->offset_x, wall->offset_y);
		insert_pixel(&cub->img, col, row, color);
	//	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);
	//	mlx_do_sync(cub->mlx);
		row++;
	}
}

void	print_ceiling(t_struct *cub, t_wall *wall, int col)
{
	int row;

	row = 0;
	while (row < wall->top_strp)
	{
		insert_pixel(&cub->img, col, row, cub->map.ceil_rgb);
		row++;
	}
}

void	print_floor(t_struct *cub, t_wall *wall, int col)
{
	int row;

	row = wall->btm_strp;
	while (row < cub->map.height)
	{
		insert_pixel(&cub->img, col, row, cub->map.fl_rgb);
		row++;
	}
}