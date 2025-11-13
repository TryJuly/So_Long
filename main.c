/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:59:51 by strieste          #+#    #+#             */
/*   Updated: 2025/11/13 13:58:43 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	// if (ac != 2)
	// 	return (0);
	// ac--;
	// if (!valid_extension(av[ac]))
	// 	return (ft_printf("Error extension\n"), 0);
	// if (!is_valid_map(av[ac]))
	// 	return (0);
	print_screen();
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