/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 08:51:18 by strieste          #+#    #+#             */
/*   Updated: 2025/11/13 10:08:42 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dest;

	dest = data->addr + (y * data->length + x * (data->bits_pixel / 8));
	*(unsigned int *)dest = color;
}

int	close_mlx(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}
