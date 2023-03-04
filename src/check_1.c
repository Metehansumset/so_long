/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumset <msumset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 13:36:59 by msumset           #+#    #+#             */
/*   Updated: 2023/03/04 13:37:00 by msumset          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_ber_check(char *map_name, t_data *data)
{
	int	len;

	len = ft_strlen(map_name);
	if (map_name[len - 1] != 'r' || map_name[len - 2] != 'e'
		|| map_name[len - 3] != 'b' || map_name[len - 4] != '.')
		ft_error("Must be '.ber' extension!", data);
}

void	ft_map_check(t_data *data)
{
	static int	i = 0;
	static int	j = 0;
	while (data->map2[i])
	{
		j = 0;
		while (data->map2[i][j])
		{
			if (data->map2[i][j] == 'C')
				data->food_count++;
			else if (data->map2[i][j] == 'E')
				data->exit_count++;
			else if (data->map2[i][j] == 'P')
			{
				data->player_count++;
				data->ply_x = j;
				data->ply_y = i;
			}
			else if (data->map2[i][j] != '0' && data->map2[i][j] != '1')
				ft_error("Error! Map must include 1P or 1C or 1E.", data);
			j++;
		}
		i++;
	}
	ft_fe_count_check(data);
}

void	ft_rectangular_check(t_data *data)
{
	int	line_len1;
	int	line_len2;
	int	i;

	i = 0;
	line_len1 = ft_strlen(data->map2[0]);
	data->map_x = line_len1;
	while (data->map2[i])
	{
		line_len2 = ft_strlen(data->map2[i]);
		if (line_len2 != line_len1)
			ft_error("Error! The map is not rectangular.", data);
		i++;
	}
}

void	ft_wall_check(t_data *data)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (data->map2[i])
	{
		len++;
		i++;
	}
	data->map_y = len;
	i = 0;
	while (data->map2[0][i] && data->map2[len - 1][i])
	{
		if (data->map2[0][i] != '1' || data->map2[len - 1][i] != '1')
			ft_error("Error! The walls are not closed.", data);
		i++;
	}
	ft_wall_leftright_check(data);
}

void	ft_wall_leftright_check(t_data *data)
{
	int	i;
	int	len;

	i = 0;
	len = data->map_x;
	while (i < data->map_y)
	{
		if (data->map2[i][0] != '1' || data->map2[i][len - 1] != '1')
			ft_error("Error! The walls are not closed.", data);
		i++;
	}
	data->tmp_food_count = data->food_count;
}
