/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 23:20:19 by romanbtt          #+#    #+#             */
/*   Updated: 2021/01/27 10:33:18 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_faillure(t_struct *cub, char *error)
{
	ft_putstr_fd(error, 2);
	exit_game(cub);

}

int	exit_game(t_struct *cub)
{
	if (cub->sprites)
		free(cub->sprites);
	if (cub->ray)
		free(cub->ray);
	if (cub->bmp.buff_body)
		free(cub->bmp.buff_body);
	exit(EXIT_SUCCESS);
	return (42);
}