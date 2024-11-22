/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putncount_nbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sithomas <sithomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:22:18 by sithomas          #+#    #+#             */
/*   Updated: 2024/11/22 17:35:09 by sithomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putncount_nbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_putncount_char('-');
		count += ft_putncount_nbr(214748364);
		count += ft_putncount_char('8');
	}
	else if (n < 0)
	{
		count += ft_putncount_char('-');
		n *= -1;
		count += ft_putncount_nbr(n);
	}
	else if (n > 9)
	{
		count += ft_putncount_nbr(n / 10);
		count += ft_putncount_char(n % 10 + 48);
	}
	else
		count += ft_putncount_char(n + 48);
	return (count);
}
