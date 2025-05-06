/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paguiler <paguiler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:51:49 by paguiler          #+#    #+#             */
/*   Updated: 2025/04/27 12:45:59 by paguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned char		*dest;
	const unsigned char	*source;
	size_t				i;
	size_t				s;

	dest = (unsigned char *)dst;
	source = (const unsigned char *)src;
	i = 0;
	s = 0;
	while (src[s] != '\0')
		s++;
	if (dstsize > 0)
	{
		while (source[i] != '\0' && i < dstsize - 1)
		{
			dest[i] = source[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (s);
}
