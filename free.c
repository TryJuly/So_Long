/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:32:47 by strieste          #+#    #+#             */
/*   Updated: 2025/11/12 13:34:18 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(char **map)
{
	size_t	count;

	count = 0;
	while (map[count])
		free(map[count++]);
	free(map);
}
