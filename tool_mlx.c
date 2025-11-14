/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 08:51:18 by strieste          #+#    #+#             */
/*   Updated: 2025/11/14 14:52:42 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dest;

	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		dest = data->addr + (y * data->length + x * (data->bits_pixel / 8));
	*(unsigned int *)dest = color;
	}
}

int	close_mlx(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	return (0);
}

int key_handler(int keycode, t_data *env)
{
    if (keycode == XK_Escape)
        ft_printf("%d\n", env->count++);
    else if (keycode == 65362)
        ft_printf("%d\n", env->count++);
    else if (keycode == 65361)
        ft_printf("%d\n", env->count++);
    else if (keycode == 65364)
        ft_printf("%d\n", env->count++);
    else if (keycode == 65363)
        ft_printf("%d\n", env->count++);
    return (0);
	(void)env;
}

int mouse_handler(int mousecode, int x, int y, t_data *env)
{
    /* x and y parameters are the pixel coordinates of the mouse
     * in the window when the event was emitted
     * you can use them to check that the user clicked in a specific region
     * of the window
     */
     if (mousecode == 1)
         ft_printf("");
    //  else if (mousecode == 2)
    //      ft_printf("Right Click");
    //  else if (mousecode == 3)
    //      ft_printf("Middle Click");
    //  else if (mousecode == 4)
    //      ft_printf("Scroll UP");
    //  else if (mousecode == 5)
    //      ft_printf("Scroll DOWN");
    //  else
        //  ft_printf("%d, X = %d Y = %d\n", mousecode, x, y);
	return (0);
	(void)env;
	(void)x;
	(void)y;
}

int render(t_data *env)
{
    (void)env;
    return (0);
}
