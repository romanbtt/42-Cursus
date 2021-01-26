/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:09:06 by romanbtt          #+#    #+#             */
/*   Updated: 2021/01/25 16:21:17 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool		is_collision_at(t_map *map, float x, float y)
{
	int chk_x;
	int chk_y;

	if (x < 0 || x > map->width || y < 0 || y > map->height)
		return (true);
	chk_x = floor(x / map->tile_size);
	chk_y = floor(y / map->tile_size);
	if (chk_y >= map->row_len || chk_x >= (int)ft_strlen(map->map_2d[chk_y]))
		return (true);
	return(ft_strchr("12", map->map_2d[chk_y][chk_x]));
}

void	move_player(t_map *map, t_player *pl)
{
	float	move_step;
	float	side_step;
	t_pos	new;

	pl->rot_angle += pl->turn_direction * pl->rot_speed;
	pl->rot_angle = normalize_angle(pl->rot_angle);
	move_step = pl->walk_fwd_bwd * pl->walk_speed;
	side_step = pl->walk_rgt_lft * pl->walk_speed;
	new.x = pl->pos.x + cos(pl->rot_angle) * move_step;
	new.y = pl->pos.y + sin(pl->rot_angle) * move_step;
	if (!is_collision_at(map, new.x, new.y) && !is_collision_at(map, new.x, new.y - 2) &&
		!is_collision_at(map, new.x - 2, new.y) && !is_collision_at(map, new.x - 2, new.y - 2) &&
		!is_collision_at(map, new.x, new.y + 2) && !is_collision_at(map, new.x + 2, new.y) &&
		!is_collision_at(map, new.x + 2, new.y + 2))
		pl->pos = new;
	new.x = pl->pos.x + cos(pl->rot_angle + 0.5 * PI) * side_step;
	new.y = pl->pos.y + sin(pl->rot_angle + 0.5 * PI) * side_step;
	if (!is_collision_at(map, new.x, new.y) && !is_collision_at(map, new.x, new.y - 2) &&
		!is_collision_at(map, new.x - 2, new.y) && !is_collision_at(map, new.x - 2, new.y - 2) &&
		!is_collision_at(map, new.x, new.y + 2) && !is_collision_at(map, new.x + 2, new.y) &&
		!is_collision_at(map, new.x + 2, new.y + 2))
		pl->pos = new;	
}