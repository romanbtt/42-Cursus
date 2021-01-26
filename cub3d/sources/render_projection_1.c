/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_projection_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 21:16:01 by romanbtt          #+#    #+#             */
/*   Updated: 2021/01/25 16:53:11 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		select_texture(t_texture *text, t_ray *ray)
{
	if (ray->isray_up && !ray->hit_vert)
		text->curr = text->no;
	else if (ray->isray_down && !ray->hit_vert)
		text->curr = text->so;
	else if (ray->isray_right && ray->hit_vert)
		text->curr = text->ea;
	else if (ray->isray_left && ray->hit_vert)
		text->curr = text->we;
}

static void	calc_wall_height(t_struct *cub, t_wall *wall, int col)
{
	float dist_proj_plane;

	dist_proj_plane = (cub->map.width / 2) / tan(FOV / 2); // MOVE IN INIT
	wall->perp_dist = cub->ray[col].dist * cos(cub->ray[col].ray_angle -
		cub->player.rot_angle);
	wall->proj_wall_height = (cub->map.tile_size / wall->perp_dist) *
		dist_proj_plane;
//	wall->strp_height = (int)wall->proj_wall_height;//
	wall->top_strp = (cub->map.height / 2) - (wall->proj_wall_height / 2); // wall->top_strp = (cub->map.height / 2) - (wall->strp_height / 2);
	if (wall->top_strp < 0)
		wall->top_strp = 0;
	wall->btm_strp = (cub->map.height / 2) + (wall->proj_wall_height / 2); // wall->btm_strp = (cub->map.height / 2) + (wall->strp_height / 2);
	if (wall->btm_strp > cub->map.height)
		wall->btm_strp = cub->map.height;
}

void	render_projection(t_struct *cub)
{
	int col;
	t_wall wall;

	col = 0;
	while (col < cub->map.width)
	{
		calc_wall_height(cub, &wall, col);
		print_ceiling(cub, &wall, col);
		select_texture(&cub->text, &cub->ray[col]);
		print_wall(cub, &wall, col);
		print_floor(cub, &wall, col);
		col++;
	}
}