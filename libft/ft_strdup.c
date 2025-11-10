/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 07:49:55 by strieste          #+#    #+#             */
/*   Updated: 2025/10/02 07:49:57 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p_str;
	size_t	count;

	count = ft_strlen(s);
	p_str = malloc((count + 1) * sizeof(char));
	if (!p_str)
		return ((void *) 0);
	count = 0;
	while (s[count])
	{
		p_str[count] = s[count];
		count++;
	}
	p_str[count] = '\0';
	return (p_str);
}
