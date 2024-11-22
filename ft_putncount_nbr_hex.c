/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putncount_nbr_hex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:22:18 by sithomas          #+#    #+#             */
/*   Updated: 2024/11/22 11:37:57 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putncount_nbr_hex(unsigned int nb, char *hextype)
{
	int	count;

	count = 0;
	if (nb >= 16)
	{
		count += ft_putncount_nbr_hex(nb / 16, hextype);
		count += ft_putncount_char(hextype[nb % 16]);
	}
	else
		count += ft_putncount_char(hextype[nb]);
	return (count);
}
