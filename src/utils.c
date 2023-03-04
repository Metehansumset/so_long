/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumset <msumset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 13:34:20 by msumset           #+#    #+#             */
/*   Updated: 2023/03/04 13:34:21 by msumset          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_xy(int *x, int *y)
{
	*x = 0;
	*y = 0;
}

void	ft_xy_operation(int *x, int *y, t_data *data)
{
	if (*x == data->map_x * 64)
	{
		*x = -64;
		*y += 64;
	}
	*x += 64;
}

void	ft_render_after_move(t_data *data)
{
	mlx_clear_window(data->mlx, data->window);
	ft_put_image(data);
}

int	ft_check_movement(t_data *data, int x, int y)
{
	if (data->map2[y][x] != '1')
	{
		if (data->map2[y][x] == 'C')
			data->food_count--;
		else if (!data->food_count && data->map2[y][x] == 'E')
		{
			ft_printf("Move: %d\nCongratulations!", ++(data->move_count));
			ft_free_all(data);
			exit(EXIT_SUCCESS);
		}
		if (data->map2[y][x] == 'E')
			return (0);
		ft_printf("Move: %d\n", ++(data->move_count));
		return (1);
	}
	return (0);
}

void	ft_fe_count_check(t_data *data)
{
	if (data->food_count < 1 || data->exit_count != 1
		|| data->player_count != 1)
		ft_error("Error! Map must include 1P or 1C or 1E.", data);
}
