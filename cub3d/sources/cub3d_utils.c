/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 13:22:02 by romanbtt          #+#    #+#             */
/*   Updated: 2020/12/23 16:50:22 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_faillure(char *error)
{
	ft_putstr_fd(error, 2);
	exit(EXIT_FAILURE);
}

void	exit_success(void)
{
	exit(EXIT_SUCCESS);
}

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

void            my_mlx_pixel_put(t_struct *cub3d, int y, int x, int color)
{
    char    *dst;

    dst = cub3d->img.addr + (y * cub3d->img.line_length + x * (cub3d->img.bpp / 8));
    *(unsigned int*)dst = color;
}