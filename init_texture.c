/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:50:32 by strieste          #+#    #+#             */
/*   Updated: 2025/11/14 14:45:42 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_texture(t_data *data)
{
	data->count = 0;
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/w.xpm", &(data->size), &(data->size));
	if (!data->wall)
		return ;
	data->ground = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/g.xpm", &(data->size), &(data->size));
	if (!data->ground)
	{
		free(data->wall);
		return ;
	}
	data->player = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/p.xpm", &(data->size), &(data->size));
	if (!data->player)
	{
		free(data->wall);
		free(data->ground);
		return ;
	}
	data->collecible = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/c.xpm", &(data->size), &(data->size));
	if (!data->collecible)
	{
		free(data->wall);
		free(data->ground);
		free(data->player);
		return ;
	}
	data->exit = mlx_xpm_file_to_image(data->mlx_ptr, "./textures/e.xpm", &(data->size), &(data->size));
	if (!data->exit)
	{
		free(data->wall);
		free(data->ground);
		free(data->player);
		free(data->collecible);
		return ;
	}
}
