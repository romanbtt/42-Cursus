/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:23:48 by romanbtt          #+#    #+#             */
/*   Updated: 2021/01/27 21:13:15 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	calc_size_tile(t_struct *cub)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (i < 7)
	{
		j = 0;
		while (j < 7 - i)
		{
			if (cub->text.size[j] > cub->text.size[j + 1])
			{
				tmp = cub->text.size[j];
				cub->text.size[j] = cub->text.size[j + 1];
				cub->text.size[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (cub->text.size[0]);
}

static void	check_arguments(t_struct *cub, int argc, char **argv)
{
	if (argc < 2 || argc > 3)
		exit_faillure(cub, "Invalid number of arguments.\n");
	else if (ft_strlen(argv[1]) <= 4 ||
		ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 4))
	{
		exit_faillure(cub, "Invalid file name.\n");
	}
	else if (argc == 3 && ft_memcmp(argv[2], "--save", 6))
		exit_faillure(cub, "Invalid second argument.\n");
}

static void	check_resolution(t_struct *cub)
{
	int screen_width;
	int screen_height;

	mlx_get_screen_size(cub->mlx, &screen_width, &screen_height);
	if (cub->map.width > screen_width)
		cub->map.width = screen_width;
	if (cub->map.height > screen_height)
		cub->map.height = screen_height;
}

static void	initialisation_game(t_struct *cub)
{
	if (!(cub->mlx = mlx_init()))
		exit_faillure(cub, "Could't etablish a connection with mlx");
	check_resolution(cub);
	if (!(cub->img.img = mlx_new_image(cub->mlx, cub->map.width,
		cub->map.height)))
		exit_faillure(cub, "Could't create an image with mlx.");
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bpp,
		&cub->img.line_length, &cub->img.endian);
	if (!(cub->win = mlx_new_window(cub->mlx, cub->map.width, cub->map.height,
		TITLE_WIN)))
		exit_faillure(cub, "Could't create a window with mlx.");
}

static void	setup_game(t_struct *cub)
{
	get_texture(cub);
	cub->map.tile_size = calc_size_tile(cub);
	if (!(cub->sprites = malloc(sizeof(t_pos) * cub->map.sp_qty)))
		exit_faillure(cub, "Malloc failled to allocate 'sp->pos'");
	if (!(cub->ray = malloc(sizeof(t_ray) * cub->map.width)))
		exit_faillure(cub, "Malloc failed to allocate 'cub->ray'");
	if (!(cub->bmp.buff_body = malloc(sizeof(int) * cub->map.width * cub->map.height)))
		exit_faillure(cub, "Malloc failed to allocate 'pixel_buff'");
	get_info_sprites(cub);
	cub->player.pos.x *= cub->map.tile_size;
	cub->player.pos.y *= cub->map.tile_size;
	cub->player.rot_speed = 0.4;
	cub->player.walk_speed = 60;
}

int	main(int argc, char **argv)
{
	t_struct cub;
	
	cub = (t_struct) {0};
	check_arguments(&cub, argc, argv);
	process_map_file(&cub, argv[1]);
	initialisation_game(&cub);
	setup_game(&cub);
	if (argv[2] && !ft_memcmp(argv[2], "--save", 6))
		save_bmp(&cub);
	mlx_loop_hook(cub.mlx, update_game, &cub);
	key_event(&cub);
	mlx_loop(cub.mlx);
}