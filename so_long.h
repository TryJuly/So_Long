/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:48:44 by strieste          #+#    #+#             */
/*   Updated: 2025/11/11 14:03:48 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"
# include "./libft/libft.h"
# include <stdio.h>
# include <math.h>


char	**map_to_array(char *av);
int		number_line(char *av);
int		valid_size(char **map);
int	wall_checker(char **map);
int		main(int ac, char **av);

#endif