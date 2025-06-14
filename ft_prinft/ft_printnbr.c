/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printnbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paguiler <paguiler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:17:10 by paguiler          #+#    #+#             */
/*   Updated: 2025/05/21 18:25:22 by paguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int n)
{
	long	max_min_int;
	int		print_int;
	char	c;

	max_min_int = n;
	print_int = 0;
	if (max_min_int < 0)
	{
		write(1, "-", 1);
		print_int++;
		max_min_int = -max_min_int;
	}
	if (max_min_int > 9)
	{
		print_int += ft_printnbr(max_min_int / 10);
		print_int += ft_printnbr(max_min_int % 10);
	}
	else
	{
		c = max_min_int + '0';
		write(1, &c, 1);
		print_int++;
	}
	return (print_int);
}
