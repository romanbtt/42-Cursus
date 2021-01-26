/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:15:03 by romanbtt          #+#    #+#             */
/*   Updated: 2021/01/25 15:25:23 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_path_text(t_texture *text)
{
	char str[256];

	str[0] = '\0';
	if (!text->no.img)
		ft_strlcat(str, "Impossible to get the north's texture value\n", 45);
	if (!text->so.img)
		ft_strlcat(str, "Impossible to get the south's texture value\n", 45);
	if (!text->ea.img)
		ft_strlcat(str, "Impossible to get the east's texture value\n", 44);
	if (!text->we.img)
		ft_strlcat(str, "Impossible to get the west's texture value\n", 44);
	if (!text->sp.img)
		ft_strlcat(str, "Impossible to get the sprite's texture value\n", 46);
	if (str[0])
		exit_faillure(str);
}

static void	get_data_addr(t_texture *text)
{
	text->no.addr = mlx_get_data_addr(text->no.img, &text->no.bpp,
		&text->no.line_length, &text->no.endian);
	text->so.addr = mlx_get_data_addr(text->so.img, &text->so.bpp,
		&text->so.line_length, &text->so.endian);
	text->ea.addr = mlx_get_data_addr(text->ea.img, &text->ea.bpp,
		&text->ea.line_length, &text->ea.endian);
	text->we.addr = mlx_get_data_addr(text->we.img, &text->we.bpp,
		&text->we.line_length, &text->we.endian);
	text->sp.addr = mlx_get_data_addr(text->sp.img, &text->sp.bpp,
		&text->sp.line_length, &text->sp.endian);
}

void get_texture(t_struct *cub)
{
		cub->text.no.img = mlx_xpm_file_to_image(cub->mlx, cub->map.text_no,
			&cub->text.no.width, &cub->text.no.height);
		cub->text.so.img = mlx_xpm_file_to_image(cub->mlx, cub->map.text_so,
			&cub->text.so.width, &cub->text.so.height);
		cub->text.ea.img = mlx_xpm_file_to_image(cub->mlx, cub->map.text_ea,
			&cub->text.ea.width, &cub->text.ea.height);
		cub->text.we.img = mlx_xpm_file_to_image(cub->mlx, cub->map.text_we,
			&cub->text.we.width, &cub->text.we.height);
		cub->text.sp.img = mlx_xpm_file_to_image(cub->mlx, cub->map.text_sp,
			&cub->text.sp.width, &cub->text.sp.height);
		check_path_text(&cub->text);
		get_data_addr(&cub->text);
}