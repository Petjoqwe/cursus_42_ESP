/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paguiler <paguiler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 17:58:00 by paguiler          #+#    #+#             */
/*   Updated: 2025/04/29 18:44:22 by paguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	size_t	i;

	last = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			last = (char *)&s[i];
		}
		i++;
	}
	if ((char) c == '\0')
	{
		return ((char *)&s[i]);
	}
	return (last);
}
