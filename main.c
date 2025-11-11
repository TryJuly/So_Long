/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:59:51 by strieste          #+#    #+#             */
/*   Updated: 2025/11/11 14:04:20 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx-linux/mlx.h"

int	main(int ac, char **av)
{
	char	**map;
	
	if (ac != 2)
		return (ft_printf("Error\n"), 0);
	map = map_to_array(av[1]);
	printf("%d\n", valid_size(map));
	printf("%d\n", wall_checker(map));
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