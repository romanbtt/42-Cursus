/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 14:33:16 by romanbtt          #+#    #+#             */
/*   Updated: 2020/12/23 16:50:34 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		initialize_window(t_struct *cub3d, int argc)
{
	int screen_width;
	int screen_heigth;

	if (!(cub3d->mlx = mlx_init()))
		exit_faillure("Error initializing MLX.\n");
	mlx_get_screen_size(cub3d->mlx, &screen_width, &screen_heigth);
	if (cub3d->map.resWH[0] > screen_width)
		cub3d->map.resWH[0] = screen_width;
	if (cub3d->map.resWH[1] > screen_heigth)
		cub3d->map.resWH[1] = screen_heigth;
	if (argc == 2)
	{
		cub3d->win = mlx_new_window(cub3d->mlx, cub3d->map.resWH[0], cub3d->map.resWH[1],
			"CUB3D - robitett");
	}
	
}

void	check_arguments(int argc, char **argv)
{
	if (argc < 2 || argc > 3)
		exit_faillure("Invalid number of arguments.\n");
	else if (ft_strlen(argv[1]) <= 4 ||
		ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 4))
	{
		exit_faillure("Invalid file name.\n");
	}
	else if (argc == 3 && ft_memcmp(argv[2], "--save", 6))
		exit_faillure("Invalid second argument.\n");
}

int		main(int argc, char **argv)
{
	t_struct cub3d;

	cub3d = (t_struct) {0};
	check_arguments(argc, argv);
	read_file(argv[1], &cub3d);
	initialize_window(&cub3d, argc);
	mlx_hook(cub3d.win, 2, (1l << 0), trigger_keys, &cub3d);
	mlx_hook(cub3d.win, 3, (1L << 1), release_keys, &cub3d);
	mlx_hook(cub3d.win, 17, (1l << 17), exit_success, &cub3d);
	mlx_loop_hook(cub3d.mlx, update, &cub3d);
	mlx_loop(cub3d.mlx);
}
