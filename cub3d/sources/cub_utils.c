/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:21:02 by romanbtt          #+#    #+#             */
/*   Updated: 2021/01/26 21:29:10 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	dist_btw_pts(float x1, float x2, float y1, float y2)
{
	float	distance;

	distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	return (distance);
}

void	insert_pixel(t_img *img, int x, int y, int color)
{
    char    *dst;

    dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
    *(unsigned int*)dst = color;
}

int	pick_pixel(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	return (*(unsigned int*)dst);
}

float	normalize_angle(float angle)
{
	angle = remainderf(angle, 2 * PI);
	if (angle < 0)
		angle = 2 * PI + angle;
	return (angle);
}

bool	is_wall_at(t_map *map, int x, int y)
{
	int	row;
	int	col;

	if (x < 0 || x >= map->tile_size * map->width ||
			y < 0 || y >= map->tile_size * map->height)
	{
		return (true);
	}
	row = y / map->tile_size;
	col = x / map->tile_size;
	return (map->map_2d[row][col] == '1');
}