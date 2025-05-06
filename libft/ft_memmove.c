/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paguiler <paguiler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:33:05 by paguiler          #+#    #+#             */
/*   Updated: 2025/04/27 16:26:05 by paguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy_backwards(
	unsigned char *dest,
	const unsigned char *source,
	size_t len
)
{
	while (len > 0)
	{
		len--;
		dest[len] = source[len];
	}
}

static void	copy_forwards(
	unsigned char *dest,
	const unsigned char *source,
	size_t len
)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		dest[i] = source[i];
		i++;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	const unsigned char	*source;

	if (!dst && !src)
		return (NULL);
	dest = (unsigned char *)dst;
	source = (const unsigned char *)src;
	if (dest > source)
		copy_backwards(dest, source, len);
	else
		copy_forwards(dest, source, len);
	return (dst);
}
