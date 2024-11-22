/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putncount_unsigned_nbr.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:22:18 by sithomas          #+#    #+#             */
/*   Updated: 2024/11/22 17:35:13 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putncount_unsigned_nbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n < 0)
		return (0);
	if (n > 9)
	{
		count += ft_putncount_unsigned_nbr(n / 10);
		count += ft_putncount_char(n % 10 + 48);
	}
	else
		count += ft_putncount_char(n + 48);
	return (count);
}
