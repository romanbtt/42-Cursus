/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:06:57 by romanbtt          #+#    #+#             */
/*   Updated: 2021/01/25 15:19:56 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	select_shortest(t_ray *ray, t_helper_ray *horz, t_helper_ray *vert)
{
	if (vert->dist < horz->dist)
	{
		ray->dist = vert->dist;
		ray->hit_x = vert->hit_x;
		ray->hit_y= vert->hit_y;
		ray->hit_vert = true;
	}
	else
	{
		ray->dist = horz->dist;
		ray->hit_x = horz->hit_x;
		ray->hit_y= horz->hit_y;
		ray->hit_horz = true;
	}
}

static void	casting_ray(t_map *map, t_ray *ray, t_player *pl)
{
	t_helper_ray horz;
	t_helper_ray vert;

	horz = (t_helper_ray) {0};
	vert = (t_helper_ray) {0};
	ray->isray_down = ray->ray_angle > 0 && ray->ray_angle < PI;
	ray->isray_up = !ray->isray_down;
	ray->isray_right = ray->ray_angle < 0.5 * PI || ray->ray_angle > 1.5 * PI;
	ray->isray_left = !ray->isray_right;
	horizontal_casting(map, ray, &horz, pl);
	vertical_casting(map, ray, &vert, pl);
	if (horz.hit == true)
		horz.dist = dist_btw_pts(pl->pos.x, horz.hit_x, pl->pos.y, horz.hit_y);
	else
		horz.dist = FLT_MAX;
	if (vert.hit)
		vert.dist = dist_btw_pts(pl->pos.x, vert.hit_x, pl->pos.y, vert.hit_y);
	else
		vert.dist = FLT_MAX;
	select_shortest(ray, &horz, &vert);
}

void	raycasting(t_struct *cub)
{
	float	ray_angle;
	int		stripe_id;
	t_ray	*ray;

	stripe_id = 0;
	ray_angle = cub->player.rot_angle - (FOV / 2);
	while (stripe_id < cub->map.width)
	{
		cub->ray[stripe_id] = (t_ray) {0};
		ray = &cub->ray[stripe_id];
		ray->ray_angle = normalize_angle(ray_angle);
		casting_ray(&cub->map, ray, &cub->player);
		ray_angle += FOV / cub->map.width;
		stripe_id++;
	}
}