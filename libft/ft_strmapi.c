/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paguiler <paguiler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:25:51 by paguiler          #+#    #+#             */
/*   Updated: 2025/05/14 19:51:57 by paguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Aplica la función f a cada carácter de s, creando una nueva string
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			len;
	char			*res;

	i = 0;
	if (!s || !f)
	{
		return (NULL);
	}
	len = ft_strlen(s);
	res = malloc(len + 1);
	if (!res)
	{
		return (NULL);
	}
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
