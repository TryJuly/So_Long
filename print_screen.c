/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:27:46 by strieste          #+#    #+#             */
/*   Updated: 2025/11/13 15:04:23 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handel_input(int keysym, t_data *data);

void	print_screen(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
	{
		ft_printf("Error mlx init\n");
		return ;
	}
	data.mlx_win = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "So_Long");
	if (!data.mlx_win)
	{
		free(data.mlx_ptr);
		ft_printf("Error new window\n");
		return ;
	}
	// mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, data.img, 500, 500);
	mlx_key_hook(data.mlx_win, handel_input, &data.mlx_ptr);
	mlx_hook(data.mlx_win, 4, 0, mouse_handler, &data);
	mlx_mouse_hook(data.mlx_win, mouse_handler, &data.mlx_ptr);
	mlx_hook(data.mlx_win, 2, 1L << 0, key_handler, &data);
	// mlx_hook(data.mlx_win, 17, 1L << 0, close_window, &data);
	// mlx_loop_hook(data.mlx_ptr, render, &data);
	mlx_loop(data.mlx_ptr);
}

int	handel_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		ft_printf("The %d pressed\n", keysym);
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
	ft_printf("%d key pressed\n", keysym);
	return (0);
}
