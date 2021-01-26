/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:09:13 by romanbtt          #+#    #+#             */
/*   Updated: 2021/01/25 16:22:24 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		print_sprite(t_struct *cub, int i)
{
	int x;
	int y;
	int color;
	t_sprites *sp;

	y = 0;
	sp = &cub->sprites[i];
	while (y < sp->size)
	{
		if (sp->offset_y + y >= 0 && sp->offset_y + y < cub->map.height)
		{
			x = 0;
			while (x < sp->size)
			{
				if ((sp->offset_x + x >= 0 && sp->offset_x + x < cub->map.width) &&
				(cub->ray[sp->offset_x + x].dist > sp->pl_dist))
				{
					color = pick_pixel(&cub->text.sp,
						x * cub->text.sp.height / sp->size,
						y * cub->text.sp.width / sp->size);
					if (color != 0)
						insert_pixel(&cub->img, sp->offset_x + x, sp->offset_y + y, color);
				}
				x++;
			}
		}
		y++;
	}
}

static	void	calc_sprites(t_struct *cub)
{
	int i;
	t_sprites *sp;
	t_player *pl;

	i = 0;
	pl = &cub->player;
	while (i < cub->map.sp_qty)
	{
		sp = &cub->sprites[i];
		
		sp->dir = atan2(sp->pos_y - pl->pos.y, sp->pos_x - pl->pos.x);
		while (sp->dir - pl->rot_angle > PI)
			sp->dir -= 2 * PI;
		while (sp->dir - pl->rot_angle < -PI)
			sp->dir += 2 * PI;
		sp->pl_dist = dist_btw_pts(pl->pos.x, sp->pos_x, pl->pos.y,
			sp->pos_y);
		sp->size = cub->map.width / sp->pl_dist * cub->map.tile_size;
		sp->offset_y = (cub->map.height / 2) - (sp->size / 2);
		sp->offset_x = (sp->dir - pl->rot_angle) * cub->map.width / FOV +
			(cub->map.width / 2) - (sp->size / 2);
		i++;
	}
}

void	sort_sprites(t_struct *cub)
{
	int i;
	int j;
	t_sprites temp;

	i = 0;
	while (i < cub->map.sp_qty)
	{
		j = 0;
		while (j < cub->map.sp_qty - 1)
		{
			if (cub->sprites[j].pl_dist < cub->sprites[j + 1].pl_dist)
			{
				temp = cub->sprites[j];
				cub->sprites[j] = cub->sprites[j + 1];
				cub->sprites[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	render_sprites(t_struct *cub)
{
	int i;

	i = 0;
	calc_sprites(cub);
	sort_sprites(cub);
	while (i < cub->map.sp_qty)
	{
		print_sprite(cub, i);
		i++;
	}
}