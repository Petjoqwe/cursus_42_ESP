/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paguiler <paguiler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 20:41:22 by paguiler          #+#    #+#             */
/*   Updated: 2025/05/13 19:24:59 by paguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Reserva una nueva string con la parte de s1 sin los caracteres de set
static char	*create_trimmed(const char *s1, size_t start, size_t end)
{
	char	*result;
	size_t	len;

	len = end - start;
	result = malloc(len + 1);
	if (!result)
	{
		return (NULL);
	}
	ft_strlcpy(result, s1 + start, len + 1);
	return (result);
}

// Elimina caracteres iniciales y finales presentes en set
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
	{
		return (NULL);
	}
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
	{
		start++;
	}
	while (end > start && ft_strchr(set, s1[end - 1]))
	{
		end--;
	}
	return (create_trimmed(s1, start, end));
}
