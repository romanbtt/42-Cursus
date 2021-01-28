/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:08:40 by romanbtt          #+#    #+#             */
/*   Updated: 2021/01/27 10:11:48 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_in_buffer(unsigned char *buff, unsigned int val)
{
	buff[0] = (unsigned char)(val);
	buff[1] = (unsigned char)(val >> 8);
	buff[2] = (unsigned char)(val >> 16);
	buff[3] = (unsigned char)(val >> 24);
}

static void	write_body_bmp(t_struct *cub, t_bmp *bmp, int fd)
{
	int x;
	int y;
	int	i;

	i = 0;
	y = cub->map.height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < cub->map.width)
			bmp->buff_body[i++] = pick_pixel(&cub->img, x++, y);
		y--;
	}
	if (!(write(fd, &bmp->buff_body[0], cub->map.height * cub->map.width * 4)))
		exit_faillure(cub, "Write failed to write the body of the bmp file");
}

static void	write_header_bmp(t_struct *cub, t_bmp *bmp, int fd)
{
	unsigned int	size;
	
	ft_memset(&bmp->buff_header, 0, 54);
	size = cub->map.width * cub->map.height * (cub->img.bpp / 8) + 54;
	bmp->buff_header[0] = 0x42;
	bmp->buff_header[1] = 0x4D;
	put_in_buffer(&bmp->buff_header[2], size);
	bmp->buff_header[10] = (0x36);
	bmp->buff_header[14] = (0x28);
	put_in_buffer(&bmp->buff_header[18], cub->map.width);
	put_in_buffer(&bmp->buff_header[22], cub->map.height);
	bmp->buff_header[26] = (0x1);
	put_in_buffer(&	bmp->buff_header[28], cub->img.bpp);
	if (!(write(fd, &bmp->buff_header, 54)))
		exit_faillure(cub, "Write failed to write the header of the bmp file");
}

void		save_bmp(t_struct *cub)
{
	int fd;
	
	if (!(fd = open("img_cub3d.bmp", O_CREAT | O_WRONLY | O_APPEND, 444)))
		exit_faillure(cub, "Could't create a .bmp file\n");
	raycasting(cub);
	render_projection(cub);
	render_sprites(cub);
	write_header_bmp(cub, &cub->bmp, fd);
	write_body_bmp(cub, &cub->bmp, fd);
	close(fd);
	exit_game(cub);
}