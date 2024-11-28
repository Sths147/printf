/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:42:56 by sithomas          #+#    #+#             */
/*   Updated: 2024/11/28 13:47:57 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_this_arg(char c, va_list args)
{
	if (c == 'c')
		return (ft_putncount_char(va_arg(args, int)));
	else if (c == 's')
		return (ft_putncount_str(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_putncount_ptr(va_arg(args, size_t)));
	else if (c == 'd' || c == 'i')
		return (ft_putncount_nbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putncount_unsigned_nbr(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_putncount_nbr_hex(va_arg(args, unsigned int), SMALL_HEX));
	else if (c == 'X')
		return (ft_putncount_nbr_hex(va_arg(args, unsigned int), CAP_HEX));
	else if (c == '%')
		return (ft_putncount_char('%'));
	return (-1);
}

static int	ft_checknprint_arg(const char **s, va_list args)
{
	int	count;

	if (**s == '%')
	{
		(*s)++;
		if (!*s)
			return (-1);
		count = ft_print_this_arg(**s, args);
	}
	else
		count = ft_putncount_char(**s);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;
	int		check;

	count = 0;
	if (!s)
		return (-1);
	if (s)
	{
		va_start(args, s);
		while (*s)
		{
			check = ft_checknprint_arg(&s, args);
			if (check < 0)
				return (-1);
			count += check;
			s++;
		}
		va_end(args);
	}
	return (count);
}
