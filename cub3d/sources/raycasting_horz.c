/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_horz.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 21:03:47 by romanbtt          #+#    #+#             */
/*   Updated: 2021/01/25 15:19:58 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void 	increment_horz(t_map *map, t_ray *ray, t_helper_ray *horz)
{
	int max_width;
	int max_height;

	max_width = map->tile_size * map->col_len;
	max_height = map->tile_size * map->row_len;
	while (horz->intcp_x >= 0 && horz->intcp_x <= max_width &&
		horz->intcp_y >= 0 && horz->intcp_y <= max_height)
	{
		horz->chk_x = horz->intcp_x;
		if (ray->isray_up)
			horz->chk_y = horz->intcp_y - 1;
		else
			horz->chk_y = horz->intcp_y;
		if (is_wall_at(map, horz->chk_x, horz->chk_y))
		{
			horz->hit = true;
			horz->hit_x = horz->intcp_x;
			horz->hit_y = horz->intcp_y;
			break;
		}
		horz->intcp_x += horz->step_x;
		horz->intcp_y += horz->step_y;
	}
}

void	horizontal_casting(t_map *map, t_ray *ray, t_helper_ray *horz,
	t_player *pl)
{
	horz->intcp_y = floor(pl->pos.y / map->tile_size) * map->tile_size;
	if (ray->isray_down)
		horz->intcp_y += map->tile_size;
	horz->intcp_x = pl->pos.x + (horz->intcp_y - pl->pos.y) /
		tan(ray->ray_angle);
	horz->step_y = map->tile_size;
	if (ray->isray_up)
		horz->step_y *= -1;
	horz->step_x = map->tile_size / tan(ray->ray_angle);
	if (ray->isray_left && horz->step_x > 0)
		horz->step_x *= -1;
	if (ray->isray_right && horz->step_x < 0)
		horz->step_x *= -1;
	increment_horz(map, ray, horz);	
}
