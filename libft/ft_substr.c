/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 07:50:59 by strieste          #+#    #+#             */
/*   Updated: 2025/10/03 17:30:32 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_error(char *p_substr)
{
	p_substr = malloc(sizeof(char));
	if (!p_substr)
		return ((void *)0);
	p_substr[0] = '\0';
	return (p_substr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p_substr;
	size_t	count;

	p_substr = ((void *)0);
	if ((!s) || start >= ft_strlen(s))
		return (ft_error(p_substr));
	count = 0;
	if ((ft_strlen(s) - start) < len)
		len = ft_strlen(s) - start;
	p_substr = malloc((len + 1) * sizeof(char));
	if (!p_substr)
		return ((void *) 0);
	while (len && s[start] && start != ft_strlen(s))
	{
		p_substr[count] = s[start];
		count++;
		start++;
		len--;
	}
	p_substr[count] = '\0';
	return (p_substr);
}
