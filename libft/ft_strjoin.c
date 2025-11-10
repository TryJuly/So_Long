/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 07:50:07 by strieste          #+#    #+#             */
/*   Updated: 2025/10/04 11:10:36 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	count;
	size_t	count_s;
	char	*p_strjoint;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	count = (ft_strlen(s1) + ft_strlen(s2));
	p_strjoint = malloc((count + 1) * sizeof(char));
	if (!p_strjoint)
		return ((void *) 0);
	count = 0;
	count_s = 0;
	while (s1[count])
		p_strjoint[count++] = s1[count_s++];
	count_s = 0;
	while (s2[count_s])
		p_strjoint[count++] = s2[count_s++];
	p_strjoint[count] = '\0';
	return (p_strjoint);
}
