/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:59:51 by strieste          #+#    #+#             */
/*   Updated: 2025/11/13 10:05:40 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx-linux/mlx.h"

int	main(int ac, char **av)
{
	t_vars	vars;
	// t_data	img;
	(void)ac;
	(void)av;
	// if (ac != 2)
	// 	return (0);
	// ac--;
	// if (!valid_extension(av[ac]))
	// 	return (ft_printf("Error extension\n"), 0);
	// if (!is_valid_map(av[ac]))
	// 	return (0);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 800, "So_Long");
	mlx_hook(vars.win, 2, 1L<<0, close_mlx, &vars);
	mlx_loop(vars.mlx);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_pixel, &img.length, &img.endian);
	// pixel_put(&img, 100, 100, 0x0000FF00);
	// mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	// (void)mlx_window;
	ft_printf("Valide\n");
	return (0);
}

// void	*mlx;
	// (void)av;
	// // void	*mlx_window;

	// mlx = mlx_init();
	// if (!mlx)
	// 	return (0);
	// mlx_new_window(mlx, 500, 500, "So_Long");
	// mlx_loop(mlx);