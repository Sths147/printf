/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putncount_nbr_hex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:22:18 by sithomas          #+#    #+#             */
/*   Updated: 2024/11/21 19:48:16 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putncount_nbr_hex(long nb, char *hextype)
{
	int	count;

	count = 0;
	if (nb == LONG_MIN)
	{
		count += ft_putncount_nbr_hex(nb / 16, hextype);
		count += ft_putncount_char((unsigned char)hextype[nb % 16]);
	}
	if (nb < 0)
	{
		count += ft_putncount_char('-');
		nb = -nb;
		count += ft_putncount_nbr_hex(nb, hextype);
	}
	else if (nb >= 16)
	{
		count += ft_putncount_nbr_hex(nb / 16, hextype);
		count += ft_putncount_char((unsigned char)hextype[nb % 16]);
	}
	else
		count += ft_putncount_char((unsigned char)hextype[nb]);
	return (count);
}
