/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:55:03 by strieste          #+#    #+#             */
/*   Updated: 2025/11/14 14:29:33 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_map(t_data *data, char **map)
{
	t_pos_map	pos;
	
	pos.y = 0;
	while (map[pos.y])
	{
		pos.x = 0;
		while (map[pos.y][pos.x])
		{
			if (map[pos.y][pos.x] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->wall, pos.x * data->size, pos.y * data->size);
			if (map[pos.y][pos.x] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->collecible, pos.x * data->size, pos.y * data->size);
			if (map[pos.y][pos.x] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->ground, pos.x * data->size, pos.y * data->size);
			if (map[pos.y][pos.x] == 'P')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->ground, pos.x * data->size, pos.y * data->size);
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->player, pos.x * data->size, pos.y * data->size);
			}
			if (map[pos.y][pos.x] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->exit, pos.x * data->size, pos.y * data->size);
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}
