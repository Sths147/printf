/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putncount_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:22:18 by sithomas          #+#    #+#             */
/*   Updated: 2024/11/22 17:35:10 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putncount_ptr_hex(size_t nb, char *hextype);

int	ft_putncount_ptr(size_t nb)
{
	int	count;

	if (nb == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count = 0;
	count += ft_putncount_str("0x");
	count += ft_putncount_ptr_hex(nb, SMALL_HEX);
	return (count);
}

static int	ft_putncount_ptr_hex(size_t nb, char *hextype)
{
	int	count;

	count = 0;
	if (nb >= 16)
	{
		count += ft_putncount_ptr_hex(nb / 16, hextype);
		count += ft_putncount_char(hextype[nb % 16]);
	}
	else
		count += ft_putncount_char(hextype[nb]);
	return (count);
}
