/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:23:10 by romanbtt          #+#    #+#             */
/*   Updated: 2020/12/23 17:56:33 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define COLOR_PLAYER 0x00000080
#define TURN_SPEED 0.02
#define WALK_SPEED 0.05

void	render_player(t_struct *cub3d)
{
	int row;
	int col;
	int tile_size;

	tile_size = calc_tile_size(cub3d) * 1;
//	row = 0;
//	while (row < tile_size)
	//{
	//	col = 0;
	//	while (col < tile_size)
	//	{
	//		if (col == tile_size / 2 && row == tile_size / 2)
	//		{	
				draw_player(cub3d, cub3d->player.pos_XY[0] * tile_size + tile_size / 2, cub3d->player.pos_XY[1] * tile_size + tile_size / 2);
				draw_line(cub3d, cub3d->player.pos_XY[0] * tile_size + tile_size / 2, cub3d->player.pos_XY[1] * tile_size + tile_size / 2);
	//		}	
	//		col++;
	//	}
	//	row++;
//	}
}

void	render_map(t_struct *cub3d)
{
	int row;
	int col;
	int nb_col;

	row = 0;
	while (row < cub3d->map.nb_row)
	{
		col = 0;
		nb_col = ft_strlen(cub3d->map.map_2d[row]);
		while (col < nb_col)
		{
			if (cub3d->map.map_2d[row][col] == '1')
				draw_wall_2d(cub3d, row, col);
			col++;
		}
		row++;
	}
	
}

void render(t_struct *cub3d)
{
	render_map(cub3d);
//	render_rays();
	render_player(cub3d);
	
}

void	move_player(t_struct *cub3d)
{
	float move_step;
	int new_player_X;
	int new_player_Y;

	cub3d->player.rotation_angle += cub3d->player.turn_direction * TURN_SPEED;
	cub3d->player.pos_XY[0] += cub3d->player.walk_direction;
	//cub3d->player.pos_XY[1] += cub3d->player.walk_direction;



}

void	update(t_struct *cub3d)
{
	
	cub3d->img.img = mlx_new_image(cub3d->mlx, cub3d->map.resWH[0], cub3d->map.resWH[1]);
	cub3d->img.addr = mlx_get_data_addr(cub3d->img.img, &cub3d->img.bpp, &cub3d->img.line_length,
		&cub3d->img.endian);
			move_player(cub3d);
	render(cub3d);
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->img.img, 0, 0);
	mlx_destroy_image(cub3d->mlx, cub3d->img.img);

}