/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:42:56 by sithomas          #+#    #+#             */
/*   Updated: 2024/11/22 11:39:45 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_this_arg(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putncount_char(va_arg(args, int));
	else if (c == 's')
		count += ft_putncount_str(va_arg(args, char *));
	else if (c == 'p')
		count += ft_putncount_ptr(va_arg(args, size_t));
	else if (c == 'd' || c == 'i')
		count += ft_putncount_nbr(va_arg(args, int));
	else if (c == 'u')
		count += ft_putncount_unsigned_nbr(va_arg(args, unsigned int));
	else if (c == 'x')
		count += ft_putncount_nbr_hex(va_arg(args, unsigned int), SMALL_HEX);
	else if (c == 'X')
		count += ft_putncount_nbr_hex(va_arg(args, unsigned int), CAP_HEX);
	else if (c == '%')
		count += ft_putncount_char('%');
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, s);
	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] != '%' && s[i])
			count += ft_putncount_char(s[i++]);
		if (s[i] == '%' && s[i + 1])
		{
			i++;
			count += ft_print_this_arg(s[i], args);
			i++;
		}
	}
	return (count);
}
