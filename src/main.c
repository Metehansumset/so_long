/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumset <msumset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 13:35:26 by msumset           #+#    #+#             */
/*   Updated: 2023/03/04 13:35:27 by msumset          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *msg, t_data *data)
{
	ft_printf(msg);
	ft_free_all(data);
	exit(EXIT_FAILURE);
}

int	ft_close_window(t_data *data)
{
	ft_free_all(data);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_free_all(t_data *data)
{
	int	i;

	i = 0;
	if (data->map1)
		free(data->map1);
	if (data->map2)
	{
		while (data->map2[i])
		{
			free(data->map2[i]);
			i++;
		}
		free(data->map2);
	}
}

void	ft_free_mlx(t_data *data)
{
	mlx_destroy_image(data->mlx, data->background);
	mlx_destroy_image(data->mlx, data->food);
	mlx_destroy_image(data->mlx, data->wall);
	mlx_destroy_image(data->mlx, data->exit);
	mlx_destroy_image(data->mlx, data->player_l);
	mlx_destroy_image(data->mlx, data->player_r);
	mlx_destroy_image(data->mlx, data->player_b);
	mlx_destroy_image(data->mlx, data->player_f);
	mlx_destroy_window(data->mlx, data->window);
	free(data->mlx);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 2)
	{
		data = ft_calloc(sizeof(t_data), 1);
		ft_ber_check(av[1], data);
		ft_make_map(data, av[1]);
		ft_map_check(data);
		ft_rectangular_check(data);
		ft_wall_check(data);
		ft_validmap_check(data, data->ply_x, data->ply_y);
		ft_path_check(data);
		data->mlx = mlx_init();
		ft_init_image(data);
		mlx_hook(data->window, 2, 1L << 0, ft_key_event, data);
		mlx_hook(data->window, 17, 1L << 2, ft_close_window, data);
		mlx_loop(data->mlx);
	}
	else
	{
		data = ft_calloc(sizeof(t_data), 1);
		ft_error("You just have to enter the map path!", data);
	}
}
