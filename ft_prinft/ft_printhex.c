/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paguiler <paguiler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:21:39 by paguiler          #+#    #+#             */
/*   Updated: 2025/05/21 18:28:11 by paguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned int n, char format)
{
	int		printed_chars;
	char	*hex_base;
	char	c;

	printed_chars = 0;
	if (format == 'X')
		hex_base = "0123456789ABCDEF";
	else
		hex_base = "0123456789abcdef";
	if (n >= 16)
		printed_chars += ft_printhex(n / 16, format);
	c = hex_base[n % 16];
	write(1, &c, 1);
	printed_chars++;
	return (printed_chars);
}
