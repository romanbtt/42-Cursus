/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:42:38 by romanbtt          #+#    #+#             */
/*   Updated: 2021/01/27 10:26:59 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define ESC 65307
#define LEFT_ARROW 65361
#define RIGHT_ARROW 65363
#define W_KEY 119
#define S_KEY 115
#define A_KEY 97
#define D_KEY 100
#define	MAP 109

static	int trigger_keys(int keycode, t_struct *cub)
{
	if (keycode == ESC)
		exit_game(cub); // TO DO
	if (keycode == RIGHT_ARROW)
		cub->player.turn_direction = 1;
	if (keycode == LEFT_ARROW)
		cub->player.turn_direction = -1;
	if (keycode == W_KEY)
		cub->player.walk_fwd_bwd = 1;
	if (keycode == S_KEY)
		cub->player.walk_fwd_bwd = -1;
	if (keycode == D_KEY)
		cub->player.walk_rgt_lft = 1;
	if (keycode == A_KEY)
		cub->player.walk_rgt_lft = -1;
	return (0);
}

static	int	release_keys(int keycode, t_struct *cub)
{
	if (keycode == RIGHT_ARROW)
		cub->player.turn_direction = 0;
	if (keycode == LEFT_ARROW)
		cub->player.turn_direction = 0;
	if (keycode == W_KEY)
		cub->player.walk_fwd_bwd = 0;
	if (keycode == S_KEY)
		cub->player.walk_fwd_bwd = 0;
	if (keycode == A_KEY)
		cub->player.walk_rgt_lft = 0;
	if (keycode == D_KEY)
		cub->player.walk_rgt_lft= 0;	
	return (0);
}

void	key_event(t_struct *cub)
{
	mlx_hook(cub->win, 33, (1l << 17), exit_game, cub);
	mlx_hook(cub->win, 2, (1l << 0), trigger_keys, cub);
	mlx_hook(cub->win, 3, (1L << 1), release_keys, cub);
} 