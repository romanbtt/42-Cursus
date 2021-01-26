/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_vert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 21:03:47 by romanbtt          #+#    #+#             */
/*   Updated: 2021/01/25 15:19:57 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void 	increment_vert(t_map *map, t_ray *ray, t_helper_ray *vert)
{
	int max_width;
	int max_height;

	max_width = map->tile_size * map->col_len - 1;
	max_height = map->tile_size * map->row_len - 1;
	while (vert->intcp_x >= 0 && vert->intcp_x <= max_width &&
		vert->intcp_y >= 0 && vert->intcp_y <= max_height)
	{
		vert->chk_y = vert->intcp_y;
		if (ray->isray_left)
			vert->chk_x = vert->intcp_x - 1;
		else
			vert->chk_x = vert->intcp_x;
		if (is_wall_at(map, vert->chk_x, vert->chk_y))
		{
			vert->hit = true;
			vert->hit_x = vert->intcp_x;
			vert->hit_y = vert->intcp_y;
			break;
		}
		vert->intcp_x += vert->step_x;
		vert->intcp_y += vert->step_y;
	}
}

void	vertical_casting(t_map *map, t_ray *ray, t_helper_ray *vert,
	t_player *pl)
{
	
	vert->intcp_x = floor(pl->pos.x / map->tile_size) * map->tile_size;
	if (ray->isray_right)
		vert->intcp_x += map->tile_size;
	vert->intcp_y = pl->pos.y + (vert->intcp_x - pl->pos.x) *
		tan(ray->ray_angle);
	vert->step_x = map->tile_size;
	if (ray->isray_left)
		vert->step_x *= -1;
	vert->step_y = map->tile_size * tan(ray->ray_angle);
	if (ray->isray_up && vert->step_y > 0)
		vert->step_y *= -1;
	if (ray->isray_down && vert->step_y < 0)
		vert->step_y *= -1;
	increment_vert(map, ray, vert);	
}