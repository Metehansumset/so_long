/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumset <msumset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 13:36:47 by msumset           #+#    #+#             */
/*   Updated: 2023/03/04 13:36:48 by msumset          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_validmap_check(t_data *data, int x, int y)
{
	char	*p;

	p = &data->tmp_map2[y][x];
	if (*p == 'E')
		data->valid_e = 1;
	if (*p != 'E' && *p != '1')
	{
		if (*p == 'C')
			data->tmp_food_count--;
		*p = '.';
		if (data->tmp_map2[y][x + 1] != '1' &&
			data->tmp_map2[y][x + 1] != '.')
			ft_validmap_check(data, x + 1, y);
		if (data->tmp_map2[y][x - 1] != '1' &&
			data->tmp_map2[y][x - 1] != '.')
			ft_validmap_check(data, x - 1, y);
		if (data->tmp_map2[y - 1][x] != '1' &&
			data->tmp_map2[y - 1][x] != '.')
			ft_validmap_check(data, x, y - 1);
		if (data->tmp_map2[y + 1][x] != '1' &&
			data->tmp_map2[y + 1][x] != '.')
			ft_validmap_check(data, x, y + 1);
	}
}

void	ft_path_check(t_data *data)
{
	int	i;

	i = 0;
	while (data->tmp_map2[i])
	{
		free(data->tmp_map2[i]);
		i++;
	}
	free(data->tmp_map2);
	if (data->tmp_food_count != 0 || data->valid_e != 1)
		ft_error("Error! There isn't valid way to go exit.", data);
}
