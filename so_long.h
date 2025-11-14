/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:48:44 by strieste          #+#    #+#             */
/*   Updated: 2025/11/14 14:46:01 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx/mlx.h"
# include "./libft/libft.h"
# include <stdio.h>
# include <math.h>
# include <X11/keysym.h>

# define WIDTH 64
# define HEIGHT 64

typedef struct s_pos_map
{
	int	x;
	int	y;
}		t_pos_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img;
	int		size;
	void	*wall;
	void	*ground;
	void	*player;
	void	*collecible;
	void	*exit;
	char	*addr;
	int		bits_pixel;
	int		length;
	int		endian;
	int		count;
}			t_data;

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

void	my_pixel_put(t_data *data, int x, int y, int color);
int		close_mlx(t_data *vars);
int 	mouse_handler(int mousecode, int x, int y, t_data *env);
int 	key_handler(int keycode, t_data *env);
int		print_map(t_data *data, char **map);

void	init_texture(t_data *data);
int 	render(t_data *env);

/*			Free/Clean				*/

void	ft_free_map(char **map);

void	print_screen(char **map);



int		main(int ac, char **av);

#endif