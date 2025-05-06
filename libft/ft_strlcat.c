/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paguiler <paguiler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 12:48:57 by paguiler          #+#    #+#             */
/*   Updated: 2025/04/27 16:38:46 by paguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	s;
	size_t	d;
	size_t	srclen;

	s = 0;
	d = 0;
	srclen = 0;
	while (dst[d] != '\0')
		d++;
	while (src[s])
	{
		srclen++;
		s++;
	}
	if (d >= dstsize)
		return (dstsize + srclen);
	s = 0;
	while (src[s] != '\0' && (d + s + 1) < dstsize)
	{
		dst[d + s] = src[s];
		s++;
	}
	dst[d + s] = '\0';
	return (d + srclen);
}
