/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:59:51 by strieste          #+#    #+#             */
/*   Updated: 2025/11/10 15:39:32 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_windows;

	mlx = mlx_init();
	mlx_windows = mlx_new_window();
	mlx_loop(mlx);
	printf("Hello");
	return (0);
}
