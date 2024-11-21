/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:42:56 by sithomas          #+#    #+#             */
/*   Updated: 2024/11/21 19:34:48 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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
		count += ft_putncount_nbr_hex(va_arg(args, size_t), SMALL_HEX);
	else if (c == 'X')
		count += ft_putncount_nbr_hex(va_arg(args, size_t), CAP_HEX);
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

/*
Method :

*/

/*
Variadic functions (VF)

#include <stdarg.h>

can handle any number of arguments

generic prototype : type function(type param1, type param2, ..., type paramN,
	...);

has at least one fixed argument (explicited in prototype) any any optional numbers of args (... in proto)

Macros:
1. va_start(va_list args,
	void last) : initialise an args variable with va_list type.
	We will acess variadic arguments with args.
	Args is located after the last fixed argument

2. va_arg(va_list args,
	type) : extract the next argument of the list and converts it in type.

3. va_copy(va_list dest, va_list src) : create a copy of the argument list

4. va_end(va_list args) : usedto free a va_list, must be used at the end.
*/