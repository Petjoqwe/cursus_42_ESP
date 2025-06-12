/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paguiler <paguiler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:43:26 by paguiler          #+#    #+#             */
/*   Updated: 2025/05/21 18:40:48 by paguiler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_format(va_list args, const char format);
int	ft_printchar(char c);
int	ft_printstr(char *s);
int	ft_printptr(void *ptr);
int	ft_printnbr(int n);
int	ft_print_unsigned(unsigned int n);
int	ft_printhex(unsigned int n, char format);

#endif
