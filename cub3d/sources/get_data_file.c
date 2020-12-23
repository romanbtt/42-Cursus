/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:28:00 by romanbtt          #+#    #+#             */
/*   Updated: 2020/12/22 13:10:00 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#define STR_ID_MA "NSWERFC"
#define STR_ID_MI "nswerfc"
#define STR_MAP "012 NSEW"

void	get_map(char *line, t_struct *cub3d)
{
	char		*tmp;
	int			i;

	cub3d->map.nb_row++;
	i = 1;
	while (line[i - 1] != '\n' && line[i - 1] != '\0')
	{
		if (!ft_strchr(STR_MAP, line[i]))
		{
			ft_putstr_fd("The map is not valid.", 2);
			free(line);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (cub3d->map.nb_row == 1)
		cub3d->map.map = ft_strjoin(line, "\n");
	else
	{
		tmp = ft_strdup(cub3d->map.map);
		free(cub3d->map.map);
		cub3d->map.map = ft_strjoin(tmp, ft_strjoin(line, "\n"));
		free(tmp);
	} 
}

void	get_identifier(char *line, t_struct *cub3d)
{
	int						i;
	static t_array_func_id	func_id[7] = {identifier_n, identifier_s_so,
		identifier_w, identifier_e, identifier_r, identifier_f, identifier_c};

	i = 0;
	while (line[0] != STR_ID_MA[i] && line[0] != STR_ID_MI[i])
		i++;
	(*func_id[i])(line, cub3d);
	cub3d->map.count_id++;
}
