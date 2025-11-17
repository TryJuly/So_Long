/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:48:44 by strieste          #+#    #+#             */
/*   Updated: 2025/11/17 13:42:55 by strieste         ###   ########.fr       */
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
	void		*mlx_ptr;
	void		*mlx_win;

	char		**map;
	int			map_w;
	int			map_h;
	int			pos_y;
	int			pos_x;
	
	void		*p_wall;
	void		*p_ground;
	void		*p_player;
	void		*p_collectible;
	void		*p_exit;

	int			count;
	int			collectible;
	t_pos_map	exit;
	t_pos_map	player;
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
int			find_collectible(char **map);

/*			Tool_Mlx				*/

void	my_pixel_put(t_data *data, int x, int y, int color);
int		close_mlx(t_data *vars);
int 	mouse_handler(int mousecode, int x, int y, t_data *env);
int 	key_handler(int keycode, t_data *env);
int		print_map(t_data *data, char **map);

int		init_texture(t_data *data);
int 	render(t_data *env);

/*			Tool_Hook Player		*/

int	move_up(t_data *data, int y, int x);
int	move_down(t_data *data, int y, int x);
int	move_right(t_data *data, int x, int y);
int	move_left(t_data *data, int x, int y);

/*			Free/Clean				*/

void	ft_free_map(char **map);
void	ft_free_texture(t_data *data);
int		close_window(t_data *data);
void	ft_free_struct(t_data *data);

void	print_screen(char **map);

/*			Print_Image				*/

int	print_wall(t_data *data, int y, int x);
int	print_ground(t_data *data, int y, int x);
int	print_collectible(t_data *data, int y, int x);
int	print_player(t_data *data, int y, int x);
int	print_exit(t_data *data, int y, int x);

/*			Init_texture				*/

int	init_exit(t_data *data);
int	init_collectible(t_data *data);
int	init_player(t_data *data);
int	init_ground(t_data *data);
int	init_wall(t_data *data);

int		main(int ac, char **av);

#endif