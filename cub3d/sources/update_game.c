/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:04:31 by romanbtt          #+#    #+#             */
/*   Updated: 2021/01/25 16:24:46 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		update_game(t_struct *cub)
{
	move_player(&cub->map, &cub->player);
	raycasting(cub);
	render_projection(cub);
	render_sprites(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);
	mlx_do_sync(cub->mlx);
	return (0);
}