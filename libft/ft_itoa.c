/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paguiler <paguiler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 19:06:03 by paguiler          #+#    #+#             */
/*   Updated: 2025/05/18 16:12:37 by paguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_itoa_length(long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
	{
		len = 1;
	}
	if (n < 0)
	{
		len = 1;
		n *= -1;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	fill_number(char *res, long nb, size_t len)
{
	while (nb > 0)
	{
		len = len - 1;
		res[len] = (nb % 10) + '0';
		nb = nb / 10;
	}
}

char	*ft_itoa(int n)
{
	long	nb;
	size_t	len;
	char	*res;

	nb = (long)n;
	len = get_itoa_length(nb);
	res = malloc(len + 1);
	if (res == NULL)
	{
		return (NULL);
	}
	res[len] = '\0';
	if (nb == 0)
	{
		res[0] = '0';
	}
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	fill_number(res, nb, len);
	return (res);
}
