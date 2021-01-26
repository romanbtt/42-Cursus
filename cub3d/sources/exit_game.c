/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 23:20:19 by romanbtt          #+#    #+#             */
/*   Updated: 2021/01/25 15:20:18 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_faillure(char *error)
{
	ft_putstr_fd(error, 2);
	exit(EXIT_FAILURE);
}

int	exit_game(void)
{
	exit(EXIT_SUCCESS);
	return (42);
}