/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:48:44 by strieste          #+#    #+#             */
/*   Updated: 2025/11/13 10:08:37 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"
# include "./libft/libft.h"
# include <stdio.h>
# include <math.h>

typedef struct s_pos_map
{
	int	x;
	int	y;
}		t_pos_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_pixel;
	int		length;
	int		endian;
}			t_data;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;


/*			Maps_Check.c			*/

int		is_valid_map(char *av);

char	**map_to_array(char *av);
int		number_line(char *av);
int		valid_size(char **map);
int		wall_check(char **map);
char	**flood_fill(char **map, int x, int y);
int		check_all_case(char *av);
int		check_exit_player(char **map);


/*			Valid_Input.c			*/

int		valid_extension(char *argument);

/*			Tool_Player				*/

t_pos_map	find_player(char **map);
t_pos_map	find_exit(char **map);

/*			Tool_Mlx				*/

void	pixel_put(t_data *data, int x, int y, int color);
int		close_mlx(t_vars *vars);

/*			Free/Clean				*/

void	ft_free_map(char **map);




int		main(int ac, char **av);

#endif