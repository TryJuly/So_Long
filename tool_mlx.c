/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 08:51:18 by strieste          #+#    #+#             */
/*   Updated: 2025/11/17 14:26:55 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_handler(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		ft_printf("The ESC pressed\n");
		close_window(data);
	}
	else if (keycode == 65362 || keycode == 119)
		move_up(data, data->pos_y - 1, data->pos_x);
	else if (keycode == 65364 || keycode == 115)
		move_down(data, data->pos_y + 1, data->pos_x);
	else if (keycode == 65361 || keycode == 97)
		move_left(data, data->pos_y, data->pos_x - 1);
	else if (keycode == 65363 || keycode == 100)
		move_right(data, data->pos_y, data->pos_x + 1);
	if (data->collectible == 0)
	{
		data->exit = find_exit(data->map);
		print_exit(data, data->exit.x, data->exit.y);
	}
	if (data->map[data->pos_y][data->pos_x] == 'E' && data->collectible == 0)
		close_window(data);
	return (0);
}
