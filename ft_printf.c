/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:42:56 by sithomas          #+#    #+#             */
/*   Updated: 2024/11/19 15:37:00 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_printf(const char *s, ...)
{
    va_list args;
    int i;
    
    va_start(args, s);
    i = 0;
    while (s[i])
    {
        while (s[i] != '%' && s[i])
            ft_putchar_fd(s[i++], 1);
        if (s[i] == '%' && s[i + 1])
        {
            i++;
            if (s[i] == 'c')
                ft_putchar_fd(va_arg(args, int), 1);
            else if (s[i] == 's')
                ft_putstr_fd(va_arg(args, char *), 1);
            i++;
        }
    }
    return (0);
}

/*
Method :

*/

/*
Variadic functions (VF)

#include <stdarg.h>

can handle any number of arguments

generic prototype : type function(type param1, type param2, ..., type paramN, ...);

has at least one fixed argument (explicited in prototype) any any optional numbers of args (... in proto)

Macros: 
1. va_start(va_list args, void last) : initialise an args variable with va_list type. 
    We will acess variadic arguments with args.
    Args is located after the last fixed argument

2. va_arg(va_list args, type) : extract the next argument of the list and converts it in type.

3. va_copy(va_list dest, va_list src) : create a copy of the argument list

4. va_end(va_list args) : usedto free a va_list, must be used at the end.
*/