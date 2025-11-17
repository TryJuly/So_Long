/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:55:03 by strieste          #+#    #+#             */
/*   Updated: 2025/11/17 11:59:27 by strieste         ###   ########.fr       */
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
				print_wall(data, pos.x, pos.y);
			if (map[pos.y][pos.x] == 'C')
				print_collectible(data, pos.x, pos.y);
			if (map[pos.y][pos.x] == '0')
				print_ground(data, pos.x, pos.y);
			if (map[pos.y][pos.x] == 'P')
				print_player(data, pos.x, pos.y);
			if (map[pos.y][pos.x] == 'E' && data->collectible == 0)
				print_exit(data, pos.x, pos.y);
			if (map[pos.y][pos.x] == 'E' && data->collectible)
				print_ground(data, pos.x, pos.y);
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}
