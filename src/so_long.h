/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumset <msumset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 13:34:44 by msumset           #+#    #+#             */
/*   Updated: 2023/03/04 13:34:45 by msumset          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../mlx/mlx.h"

# define PL_FT "./images/player_front.xpm"
# define PL_BK "./images/player_back.xpm"
# define PL_LT "./images/player_left.xpm"
# define PL_RT "./images/player_right.xpm"
# define FOOD "./images/food.xpm"
# define EXIT "./images/door.xpm"
# define BACKG "./images/background.xpm"
# define WALL "./images/wall.xpm"

typedef struct s_data
{
	void	*mlx;
	void	*window;
	void	*player_f;
	void	*player_b;
	void	*player_r;
	void	*player_l;
	void	*exit;
	void	*wall;
	void	*food;
	void	*background;
	int		imgx;
	int		imgy;
	int		position_x;
	int		position_y;
	int		ply_x;
	int		ply_y;
	int		map_x;
	int		map_y;
	char	*map1;
	char	**map2;
	char	**tmp_map2;
	int		food_count;
	int		tmp_food_count;
	int		exit_count;
	int		player_count;
	int		valid_e;
	int		move_count;
	char	curr_pos;
	char	*move_count_screen;
}	t_data;

void	ft_ber_check(char *map_name, t_data *data);
void	ft_error(char *msg, t_data *data);
int		ft_key_event(int keycode, t_data *data);
void	ft_make_map(t_data *data, char *map);
void	ft_map_check(t_data *data);
void	ft_fe_count_check(t_data *data);
void	ft_rectangular_check(t_data *data);
void	ft_wall_check(t_data *data);
void	ft_wall_leftright_check(t_data *data);
void	ft_validmap_check(t_data *data, int x, int y);
void	ft_path_check(t_data *data);
void	ft_init_image(t_data *data);
void	ft_put_image(t_data *data);
void	ft_put_image_player(t_data *data, int x, int y);
void	ft_score(t_data *data);
void	ft_init_xy(int *x, int *y);
void	ft_xy_operation(int *x, int *y, t_data *data);
void	ft_render_after_move(t_data *data);
void	ft_check_up(int key, t_data *data);
void	ft_check_down(int key, t_data *data);
void	ft_check_right(int key, t_data *data);
void	ft_check_left(int key, t_data *data);
int		ft_check_movement(t_data *data, int x, int y);
int		ft_close_window(t_data *data);
void	ft_free_all(t_data *data);
void	ft_free_mlx(t_data *data);

#endif
