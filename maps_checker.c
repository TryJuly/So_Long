/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 08:49:05 by strieste          #+#    #+#             */
/*   Updated: 2025/11/11 14:17:23 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		number_line(char *av);
int		valid_size(char **map);
char	**map_to_array(char *av);
void	clean_array(char **map);

int	wall_checker(char **map)
{
	int	count;
	int	len;
	int	max_x;
	int	max_y;

	if (!valid_size(map))
		return (0);
	max_y = 0;
	len = 0;
	count = 0;
	max_x = ft_strlen(map[len]) - 1;
	while (map[max_y] != 0)
		max_y++;
	max_y--;
	while (len < max_y)
	{
		if (map[len][count] != '1')
			return (0);
		len++;
	}
	while (count < max_x)
	{
		if (map[len][count] != '1')
			return (0);
		count++;
	}
	while (len > 0)
	{
		if (map[len][count] != '1')
			return (0);
		len--;
	}
	while (count > 0)
	{
		if (map[len][count] != '1')
			return (0);
		count--;
	}
	return (1);
}


int	number_line(char *av)
{
	size_t	count;
	int		fd;
	char	*str;
	
	count = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (0);
	str = get_next_line(fd);
	if (!str)
		return (close(fd), -1);
	while (str)
	{
		count++;
		free(str);
		str = get_next_line(fd);
	}
	close (fd);
	return (count);
}

char	**map_to_array(char *av)
{
	int		fd;
	char	*str;
	char	**map;
	size_t	count;
	
	count = number_line(av);
	map = malloc((count + 1) * sizeof(char **));
	if (!map)
		return (NULL);
	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (0);
	str = get_next_line(fd);
	count = 0;
	while (str)
	{
		map[count] = str;
		count++;
		str = get_next_line(fd);
	}
	close(fd);
	map[count] = 0;
	clean_array(map);
	return (map);
}

void	clean_array(char **map)
{
	size_t	len;
	size_t	count;
	
	len = 0;
	while (map[len])
	{
		count = 0;
		while (map[len][count] != '\n' && map[len][count])
			count++;
		if (map[len][count] == '\n')
			map[len][count] = 0;
		len++;
	}
}

int	valid_size(char **map)
{
	size_t	count;
	size_t	check_x;
	size_t	len;
	
	len = 0;
	check_x = ft_strlen(map[len]);
	while (map[len])
	{
		count = 0;
		while (map[len][count])
			count++;
		if (count != check_x)
			return (0);
		len++;
	}
	if (len == check_x)
		return (0);
	return (1);
}