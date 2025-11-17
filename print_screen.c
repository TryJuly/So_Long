/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:27:46 by strieste          #+#    #+#             */
/*   Updated: 2025/11/17 13:42:46 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_screen(char **map)
{
	t_data		data;
	t_pos_map	pos;

	data.pos_y = 0;
	data.pos_x = 0;
	data.map = map;
	while (map[data.pos_y])
		data.pos_y++;
	while (map[data.pos_y - 1][data.pos_x])
		data.pos_x++;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
	{
		ft_printf("Error mlx init\n");
		return ;
	}
	data.mlx_win = mlx_new_window(data.mlx_ptr, data.pos_x * WIDTH, data.pos_y * HEIGHT, "So_Long");
	if (!data.mlx_win)
	{
		free(data.mlx_ptr);
		ft_printf("Error new window\n");
		return ;
	}
	init_texture(&data);
	data.collectible = find_collectible(map);
	print_map(&data, map);
	pos = find_player(map);
	data.pos_x = pos.x;
	data.pos_y = pos.y;
	mlx_hook(data.mlx_win, 2, 1L << 0, key_handler, &data);
	mlx_hook(data.mlx_win, 17, 1L << 0, close_window, &data);
	mlx_loop(data.mlx_ptr);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	ft_free_struct(data);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(1);
	return (0);
}
