/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigger_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 14:19:01 by romanbtt          #+#    #+#             */
/*   Updated: 2020/12/23 16:50:37 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define ESC 65307
#define LEFT_ARROW 65361
#define RIGHT_ARROW 65363

void trigger_keys(int keycode, t_struct *cub3d)
{
	if (keycode == ESC)
		exit_success();
	else if (keycode == RIGHT_ARROW)
		cub3d->player.turn_direction = 1;
	else if (keycode == LEFT_ARROW)
		cub3d->player.turn_direction = -1;
	else if (keycode == 'W' || keycode == 'w' || keycode == 'D' || keycode == 'd')
		cub3d->player.walk_direction = 1;
	else if (keycode == 'S' || keycode == 's' || keycode == 'A' || keycode == 'a')
		cub3d->player.walk_direction = -1;
}

void	release_keys(int keycode, t_struct *cub3d)
{
	if (keycode = RIGHT_ARROW)
		cub3d->player.turn_direction = 0;
	else if (keycode = LEFT_ARROW)
		cub3d->player.turn_direction = 0;
	else if (keycode == 'W' || keycode == 'w' ||
		keycode == 'D' || keycode == 'd')
			cub3d->player.walk_direction = 0;
	else if (keycode == 'S' || keycode == 's' ||
		keycode == 'A' || keycode == 'a')
			cub3d->player.walk_direction = 0;
}